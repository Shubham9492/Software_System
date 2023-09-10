/*
============================================================================
Name : 27e.c
Author : Shubham Suthar
Description : Write a program to execute ls -Rl by the following system calls
a) execvp
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

void main(){
	printf("Executing ls -Rl using execvp \n");
	char* ch[] = {"ls", "-R", "-l", NULL};
	execvp("ls", ch);
}
