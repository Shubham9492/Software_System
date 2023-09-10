/*
============================================================================
Name : 3.c
Author : Shubham Suthar
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call

Date: 9th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd;
	fd=creat("text.txt",O_RDONLY|O_WRONLY);
	printf("fd = %d",fd);
	if(fd==-1){
		printf("File Already exist");
	}
}
