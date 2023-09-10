/*
============================================================================
Name : 12.c
Author : Shubham Suthar
Description :  Write a program to find out the opening mode of a file. Use fcntl.
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

void main(){
	int fd=open("demo.txt",O_RDONLY);
	int m=fcntl(fd,F_GETFL);
	switch(m){
		case 32768:
			printf("Read only");
			break;
		case 32769:
			printf("Write only");
			break;
		case 32770:
			printf("Both read and write");
			break;	
		default:
			printf("not found");
			break;
	}
	close(fd);
}


