/*
============================================================================
Name : 7.c
Author : Shubham Suthar
Description :  Write a program to copy file1 into file2 ($cp file1 file2).

Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc,char* argv[]){
	if(argc!=3){
		printf("Invalid");
		return -1;
	}
	int fd_source= open(argv[1],O_RDONLY);
	int fd_dest= open(argv[2],O_WRONLY|O_CREAT);

	if(fd_source==-1 || fd_dest==-1){
		printf("Error in opening source file or dest file");
	}

	char buffer;
	ssize_t read_byte,write_byte;
	while((read_byte = read(fd_source,&buffer,1)>0)){
		write_byte= write(fd_dest,&buffer,1);
		if(write_byte!=read_byte){
			perror("Error while writing to destination file");
			break;
		}
	}


	int close_fd_source=close(fd_source);
	int close_fd_dest=close(fd_dest);

	if(close_fd_source==-1 || close_fd_dest==-1){
		printf("Error closing file");
	}
}
