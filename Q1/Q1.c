
/*
============================================================================
Name : 1.c
Author : Shubham Suthar
Description :  Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)
 
Date: 9th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int k=symlink("temp","destSL");
	if(k<0){
		perror("Failed");
		return 1;
	}
	int l=link("temp","destHL");
	if(l<0){
		perror("Failed");
		return 1;
	}
	int m=mknod("destFIFO",S_IFIFO,0);
	if(m<0)
		perror("Failed");

	return 0;
}
