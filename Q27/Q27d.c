/*
============================================================================
Name : 27d.c
Author : Shubham Suthar
Description : Write a program to execute ls -Rl by the following system calls
a) execv
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

void main(){
	
	printf("Executing ls -Rl using execv \n");
	char* ch[] = {"ls", "-R", "-l", NULL};
	execv("/bin/ls",ch);
}
