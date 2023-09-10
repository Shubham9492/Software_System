/*
============================================================================
Name : 9.c
Author : Shubham Suthar
Description : Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
 
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<time.h>

void main(){
	struct stat info;
	stat("./file1.txt",&info);
	printf("File Information :-\n");
	printf("Inode: %lu \n",info.st_ino);
	printf("Number of hard links: %ld \n",info.st_nlink);
	printf("Uid: %d \n",info.st_uid);
	printf("Gid: %d \n",info.st_gid);
	printf("Size: %ld \n",info.st_size);
	printf("Block size: %ld \n",info.st_blksize);
	printf("Number of blocks: %ld \n",info.st_blocks);
	printf("Time of last access: %s",ctime(&info.st_atime));
	printf("Time of last modification: %s",ctime(&info.st_mtime));
	printf("Time of last change: %s",ctime(&info.st_ctime));
}

