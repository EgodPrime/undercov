#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include<iostream>
#include <stdlib.h>
#include <signal.h>

#include "undercov.h"

int shmid;
unsigned char* m_data;
FILE* fp;
unsigned int undercov_cnt;
// reset the compile cnt file
char* filename = "/tmp/undercov_cnt";

void signal_handler(int sig){
    fp = fopen(filename, "r");
    fread(&undercov_cnt, 4, 1, fp);
    std::cerr<<"\nDMC-COV totally inserts "<<undercov_cnt<<" blocks\n";
    fclose(fp);
    shmdt(m_data);
    shmctl(shmid, IPC_RMID, NULL);
    exit(0);
}

int main(){
    // open share memory for some cases where execution happens during compilation
    shmid = shmget(shm_key, bytemap_size*2, 0666 | IPC_CREAT);
    m_data = (unsigned char*) shmat(shmid, NULL, 0);

    fp = fopen(filename, "w+");
    if(fp == NULL){
        std::cerr<<"Failed to open or create /tmp/undercov_cnt!\n";
        return 1;
    }
    fprintf(fp, "%s", "");
    fclose(fp);
    
    signal(SIGINT, signal_handler);
    while(1){
        fp = fopen(filename, "r");
        fread(&undercov_cnt, 4, 1, fp);
        fclose(fp);
        std::cerr<<"DMC-COV currently has inserted "<<undercov_cnt<<" blocks\n";
        sleep(1);
    }
}