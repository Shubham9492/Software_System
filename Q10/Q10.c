/*
============================================================================
Name : 10.c
Author : Shubham Suthar
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes. 
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data.
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

void main(int argc,char* argv[]){
	if(argc!=2){
		printf("Please give two argument");
		return;
	}
	int fd=open(argv[1],O_RDWR);
	if(fd==-1){
		printf("Error while opening a file");
		return;
	}

	int k=write(fd,"abcdefghij",10);
	if(k==-1){
		printf("Error");
		return;
        }
	int move=lseek(fd,10,SEEK_CUR);
	write(fd,"abcdefghij",10);
	move=lseek(fd,0,SEEK_CUR);
	printf("%d",move);
	close(fd);
}
