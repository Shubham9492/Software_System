/*
============================================================================
Name : 4.c
Author : Shubham Suthar
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Date: 9th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

void main(){
	int fd=open("test.txt",O_RDONLY|O_CREAT|O_EXCL);
	printf("fd: %d",fd);
	if(fd==-1){
		printf("Error");
	}
}
