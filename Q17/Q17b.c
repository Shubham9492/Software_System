/*
============================================================================
Name : 17b.c
Author : Shubham Suthar
Description :   Write a separate program, to 
open the file, implement write lock, read the ticket number, increment the number and print 
the new ticket number then close the file
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


int main(){
	int t_ticket;
	int fd,inp;
	fd=open("train.txt",O_RDWR);
	if(fd==-1){
		printf("Error while opening a file");
		return 0;
	}
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before CS \n");
	fcntl(fd,F_SETLKW,&lock);
	read(fd,&t_ticket,sizeof(t_ticket));
	printf("Ticket no %d \n",t_ticket);
	t_ticket++;
	printf("Enter to Unlock");
	getchar();
	lseek(fd,0,SEEK_SET);
	write(fd,&t_ticket,sizeof(t_ticket));
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Done :)");
	close(fd);
	return 0;
}



