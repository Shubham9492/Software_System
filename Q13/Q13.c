/*
============================================================================
Name : 13.c
Author : Shubham Suthar
Description :  Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to 
verify whether the data is available within 10 seconds or not (check in $man 2 select).
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/select.h>

int main(){
	fd_set s;
	struct timeval tlim;
	FD_ZERO(&s);
	FD_SET(0,&s);
	tlim.tv_sec=10;
	
	int k=select(1,&s,NULL,NULL,&tlim);
	if(k)
		printf("Data Available :)\n");
	else
		printf("Data Unavailable :(");
	return 0;
}

