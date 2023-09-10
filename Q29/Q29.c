/*
============================================================================
Name : 29.c
Author : Shubham Suthar
Description :  Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, 
SCHED_RR).
  
Date: 9th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    struct sched_param param;
    int pid=getpid();
    int sc_policy = sched_getscheduler(pid); 

    printf("Current Scheduling Policy =");
    switch (sc_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("None\n");
            break;
    }

    printf("Current Priority: %d\n", param.sched_priority);
    param.sched_priority = sched_get_priority_max(sc_policy);
    
    printf("\nScheduling policy changed to SCHED_RR\n");
    
    if((sched_setscheduler(pid,SCHED_RR,&param))==-1){
    printf("Error");
    return 0;
    }

    printf("New scheduling policy: ");
    switch (sc_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("None\n");
            break;
    }

    return 0;
}


