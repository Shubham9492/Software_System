/*
============================================================================
Name : 27c.c
Author : Shubham Suthar
Description : Write a program to execute ls -Rl by the following system calls
a) execle
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

void main(){
	printf("Executing ls -Rl using execle \n");
	char* ch[]={NULL};
	execle("/bin/ls", "ls", "-R", "-l", NULL,ch);
}
