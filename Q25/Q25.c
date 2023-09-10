/*
============================================================================
Name : 25.c
Author : Shubham Suthar
Description :   Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call).
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
	int pid1,pid2,pid3;
	pid1=fork();
	if(pid1==0){
		printf("Parent of first child's id=%d\n",getppid());
		printf("First child pid= %d\n",getpid());
	}else if(pid1>0){
		pid2=fork();
		if(pid2==0){
		sleep(5);
			printf("Parent of second child's id=%d\n",getppid());
			printf("Second child pid= %d\n",getpid());
		}else if(pid2>0){
			pid3=fork();
			if(pid3==0){
				sleep(4);
				printf("Parent of Third child's id=%d\n",getppid());
				printf("Third child pid= %d\n",getpid());
	         	}else if(pid3>0){
	         		int k=waitpid(pid2,NULL,0);
	         		printf("waitpid= %d\n",k);
	         		printf("Parent id=%d\n",getpid());
	         	}	
		}
	}
}
