/*
============================================================================
Name : 20.c
Author : Shubham Suthar
Description : Find out the priority of your running program. Modify the priority with nice command.
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>

int main(){
	struct sched_param s;
	printf("Process ID: %d \n",getpid());
	printf("Current Priority: %d \n",s.sched_priority);
	int newPri=nice(8);
	printf("Modified Priority: %d \n",newPri);
	return 1;
}

