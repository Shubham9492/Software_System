/*
============================================================================
Name : 16b.c
Author : Shubham Suthar
Description :   Write a program to perform mandatory locking.
 b. Implement read lock
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

void main(){
	struct flock lock;
	int fd;
	fd=open("test.txt",O_RDONLY);
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before CS\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("In Critical Section\n");
	printf("Press enter to unlock\n");
	getchar();
	printf("Unlocked\n");
	lock.l_type=F_ULOCK;
	fcntl(fd,F_SETLK,&lock);
	printf("DONE\n");
}
