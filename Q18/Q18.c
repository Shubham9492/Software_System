/*
============================================================================
Name : 18.c
Author : Shubham Suthar
Description :  Write a program to perform Record locking.
 a. Implement write lock
 b. Implement read lock
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

struct record{
	int data;
};

int main(){
	int fd=open("record.txt",O_RDONLY|O_WRONLY);
	struct record r1,r2,r3;
	r1.data=1;r2.data=1;r3.data=1;
	write(fd,&r1,sizeof(r1));
	write(fd,&r2,sizeof(r2));
	write(fd,&r3,sizeof(r3));
	close(fd);
	return 0;
}
