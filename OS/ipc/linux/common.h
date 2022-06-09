//comm.h
#ifndef _COMM_H__
#define _COMM_H__
 
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#include<sys/wait.h>
#include<unistd.h>
#include <string>
 
#define PATHNAME "."
#define PROJ_ID 0x6666
 
int CreateShm(int size);
int DestroyShm(int shmid);
int GetShm(int size);

struct ShareInfo
{
    int a;
    std::string s;
};

#endif