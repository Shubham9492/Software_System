/*
============================================================================
Name : 24.c
Author : Shubham Suthar
Description :  Write a program to create an orphan process
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
	int pid=fork();
	if(pid>0){
		printf("Parent Process id: %d \n",getpid());
		exit(0);
	}else if(pid==0){
	        printf("In Child Process :-");
		printf("Before orphan PPID: %d \n",getppid());
		sleep(5);
		printf("After orphan PPID: %d \n",getppid());
	}
	return 0;
}
