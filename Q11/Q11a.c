/*
============================================================================
Name : 11a.c
Author : Shubham Suthar
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes. 
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data.
a) use dup
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

void main(int argc,char* argv[]){
	if(argc!=2){
		printf("Pass the argument correctly");
		return;
	}
	int fd=open(argv[1],O_RDWR);
	if(fd==-1){
		printf("Error while opening file");
		return;
	}
	int dfd= dup(fd);
	char buff[100];
	read(dfd,buff,100);
	write(1,buff,100);
	close(dfd);
	close(fd);
}


