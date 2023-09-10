/*
============================================================================
Name : 27a.c
Author : Shubham Suthar
Description : Write a program to execute ls -Rl by the following system calls
a) execl
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>

void main(void){
	execl("/bin/ls","ls","-R","-l",NULL);
}
