/*
============================================================================
Name : 8.c
Author : Shubham Suthar
Description : . Write a program to open a file in read only mode, read line by line and display each line as it is read. 
Close the file when end of file is reached.

Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char* argv[]){
	int fd_read = open(argv[1],O_RDONLY);
	if(fd_read==-1){
		printf("Error while openig a file");
		return -1;
	}
	int co=0;
	char c;
	char buffer[100];
	while(read(fd_read,&c,1)>0){
		if(c!='\n'){
			buffer[co++]=c;
		}else{
			buffer[co++]='\n';
			write(1,buffer,co);
			co=0;
		}
		
	}
	int close_read_fd=close(fd_read);
	if(close_read_fd==-1)
		printf("Error while closing a file");

	return 0;
}
