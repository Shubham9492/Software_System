/*
============================================================================
Name : 21.c
Author : Shubham Suthar
Description :  Write a program, call fork and print the parent and child process id.
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int c=fork();
	if(c){
		printf("Parent Process ID %d\n",getpid());
	}else{
		printf("Child Process ID %d\n",getpid());
		sleep(2);	
	}
	
	return 1;
}
