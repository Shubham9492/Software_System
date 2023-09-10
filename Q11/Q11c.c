/*
============================================================================
Name : 11c.c
Author : Shubham Suthar
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes. 
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data.
c) use fcntl
  
Date: 9th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Pass the argument Correctly");
		return 0;
	}
	int fd1=open(argv[1],O_RDONLY);
	char buff[200];
	int fd2=fcntl(fd1,F_DUPFD);
	if(fd2==-1){
		printf("Error");
		return 0;
	}
	printf("fd1 & fd2 : %d, %d",fd1,fd2);
	int read_d=read(fd2,&buff,sizeof(buff));
	write(1,&buff,read_d);
	close(fd1);
	close(fd2);
}
