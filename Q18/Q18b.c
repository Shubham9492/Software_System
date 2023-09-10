/*
============================================================================
Name : 18b.c
Author : Shubham Suthar
Description : Write a program to perform Record locking.
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
	int fd=open("record.txt",O_RDWR);
	int choice;
	printf("Enter record [1-3] to lock");
	scanf("%d",&choice);
	int offset = (choice-1)*sizeof(struct record);
	lseek(fd,offset,SEEK_SET);
	printf("Acquiring Lock on your choice\n");
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=offset;
	lock.l_len=sizeof(struct record);
	lock.l_pid=getpid();
	fcntl(fd,F_SETLKW,&lock);
	printf("Lock acquired\n");
	struct record cur_rec;
	read(fd,&cur_rec,sizeof(cur_rec));
	printf("Previous value of record %d\n",cur_rec.data);
	printf("Press enter to unlock \n");
	getchar();
	getchar();
	cur_rec.data++;
	printf("Now value of record %d\n",cur_rec.data);
	lseek(fd,(-1)*sizeof(struct record),SEEK_CUR);
	write(fd,&cur_rec,sizeof(cur_rec));
	printf("releasing record\n");
	lock.l_type= F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Lock released\n");
	printf("DONE :)\n");
	return 0;

}
