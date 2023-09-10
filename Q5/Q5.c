/*
============================================================================
Name : 5.c
Author : Shubham Suthar
Description :  Write a program to create five new files with infinite loop. Execute the program in the background 
and check the file descriptor table at /proc/pid/fd

Date: 9th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	while(1){
	creat("file1.txt",O_RDWR);
	creat("file2.txt",O_RDWR);
	creat("file3.txt",O_RDWR);
	creat("file4.txt",O_RDWR);
	creat("file5.txt",O_RDWR);
	sleep(10);
	}
	return 0;
}
