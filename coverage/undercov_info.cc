#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include "undercov.h"


static int shmid;
static unsigned char* m_data;

extern "C" void init_bitmap(){
    shmid = shmget(shm_key, bytemap_size*2, IPC_CREAT | 0666);

    m_data = (unsigned char*) shmat(shmid, NULL, 0);
}

extern "C" void close_bitmap(){
    shmdt(m_data);
    shmctl(shmid, IPC_RMID, NULL);
}

extern "C" unsigned int get_bb_cnt(){
    unsigned int count = 0;
    for (size_t i = 0; i < bytemap_size; i++) {
        unsigned char c = m_data[i];
        while (c > 0) {
            if (c & 1) {
                count++;
            }
            c >>= 1;
        }
    }
    return count;
}