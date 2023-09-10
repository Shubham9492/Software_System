/*
============================================================================
Name : 23.c
Author : Shubham Suthar
Description :  Write a program to create a Zombie state of the running program.
Date: 9th Sept, 2023.
============================================================================
*/
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	pid_t pid=fork();
	if(pid>0){
		printf("In Parent, pid- %d \n",getpid());
		sleep(20);
	}else
		printf("In Child, pid- %d \n",getpid());
	return 1;
}
