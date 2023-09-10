/*
============================================================================
Name : 14.c
Author : Shubham Suthar
Description :  Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Enter Argument correctly");
		return 0;
	}
	struct stat info;
	stat(argv[1],&info);
	int s_info=info.st_mode & S_IFMT;
	switch(s_info){
		case S_IFBLK:
			printf("Block File \n");
			break;
		case S_IFCHR:
			printf("Character File \n");
			break;
		case S_IFIFO:
			printf("FIFO \n");
			break;
		case S_IFDIR:
			printf("Directory \n");
			break;
		case S_IFREG:
			printf("Regular \n");
			break;
		case S_IFLNK:
			printf("Symlink \n");
			break;
		case S_IFSOCK:
			printf("Socket \n");
			break;
		default:
			printf("Invalid \n");
			break;
	}
	return 0;
}
