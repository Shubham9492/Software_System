/*
============================================================================
Name : 22.c
Author : Shubham Suthar
Description :  Write a program, open a file, call fork, and then write to the file by both the child as well as the 
parent processes. Check output of the file.
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd=open("test.txt",O_RDWR);
	if(fork()){
		write(fd,"abcdef",6);
	}else{
		write(fd,"ABCDEFG",7);
	}
	return 0;
}
