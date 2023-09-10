/*
============================================================================
Name : 11b.c
Author : Shubham Suthar
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes. 
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data.
b) use dup2
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void main(int argc,char* argv[]){
	if(argc!=2){
		printf("Pass the argument correctly");
		return;
	}
	int fd1=open(argv[1],O_RDWR);
	if(fd1==-1){
		printf("Error while opening file");
		return;
	}
	int dup2_fd= dup2(fd1,9);
	
	write(dup2_fd,"hello",5);
	write(fd1,"How are you?",12);
	close(fd1);
}
