/*
============================================================================
Name : 15.c
Author : Shubham Suthar
Description : Write a program to display the environmental variable of the user (use environ).
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(){
	int k=0;
	while(environ[k]){
		printf("%s\n",environ[k++]);
	}
	return 0;
}
