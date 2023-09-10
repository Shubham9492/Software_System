/*
============================================================================
Name : 12.c
Author : Shubham Suthar
Description :   Write a program to simulate online ticket reservation. Implement write lock 
Write a program to open a file, store a ticket number and exit. 
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	int t_ticket;
	t_ticket=0;
	int fd=open("train.txt",O_RDWR);
	if(fd==-1){
		printf("Error while opening a file");
		return 0;
	}
	write(fd,&t_ticket,sizeof(t_ticket));
	close(fd);
}

