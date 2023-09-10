/*
============================================================================
Name : 27b.c
Author : Shubham Suthar
Description : Write a program to execute ls -Rl by the following system calls
a) execlp
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

void main(){
	
	printf("Executing ls -Rl using execlp \n");
	execlp("ls", "ls", "-R", "-l", NULL);
}
