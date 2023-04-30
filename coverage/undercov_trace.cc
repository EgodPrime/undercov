#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

#include "undercov.h"

#ifdef DMC_DEBUG
#include <iostream>
#endif

static int shmid;
static unsigned char* m_data;

static bool __init__shm__ = [](){
    shmid = shmget(shm_key, bytemap_size*2, IPC_CREAT | 0666);
    m_data = (unsigned char*) shmat(shmid, NULL, 0);
    return true;
}();

extern "C" void on_bb_hit(unsigned int bb_idx){
    unsigned char data;
    unsigned int idx = bb_idx/8;
    unsigned char bit = bb_idx%8;
    unsigned char new_byte = 1<<bit;
    do
    {
        data = __atomic_load_1(m_data+idx, __ATOMIC_SEQ_CST);
        new_byte = data | new_byte;
    }
    while (!__atomic_compare_exchange_1(m_data+idx, &data, new_byte, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST));
    #ifdef DMC_DEBUG
    std::cerr<<"Basic block "<<bb_idx<<" was executed.\n";
    #endif
}