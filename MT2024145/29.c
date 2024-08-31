/*
-------------------------------------------------------
-------------------------------------------------------
Name - 29.c
Author - Shivam Pandey
Description - Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy: %d\n", policy);
            break;
    }
}

int main() {
    int pid = 0;
    struct sched_param param;
    int policy=sched_getscheduler(pid);
    if (policy==-1)
    {
        perror("sched_getscheduler failed");
        exit(EXIT_FAILURE);
    }
    print_policy(policy);
    param.sched_priority = 10;
    if(sched_setscheduler(pid,SCHED_FIFO,&param)==-1) 
    {
        perror("sched_setscheduler failed for SCHED_FIFO");
    }
    else 
    {
        printf("Scheduling policy changed to SCHED_FIFO\n");
    }
    policy=sched_getscheduler(pid);
    if(policy==-1) 
    {
        perror("sched_getscheduler failed");
        exit(EXIT_FAILURE);
    }
    print_policy(policy);
    if(sched_setscheduler(pid,SCHED_RR,&param)==-1) 
    {
        perror("sched_setscheduler failed for SCHED_RR");
    }
    else 
    {
        printf("Scheduling policy changed to SCHED_RR\n");
    }
    policy=sched_getscheduler(pid);
    if(policy==-1) 
    {
        perror("sched_getscheduler failed");
        exit(EXIT_FAILURE);
    }
    print_policy(policy);
    return 0;
}

