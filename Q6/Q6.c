/*
============================================================================
Name : 6.c
Author : Shubham Suthar
Description :  Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Date: 9th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	char buffer[20];
	ssize_t read_byte = read(STDIN_FILENO,buffer,sizeof(buffer));
	if(buffer>0){
		write(STDOUT_FILENO,buffer,read_byte);
	}
	return 0;
}
