/*
============================================================================
Name : 30.c
Author : Shubham Suthar
Description :  Write a program to run a script at a specific time using a Daemon process.
  
Date: 9th Sept, 2023.
============================================================================
*/
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

time_t rawtime;
struct tm *time_info;

int main(){
	int pid=fork();
	if(pid==0){
		printf("Child Process");
		int session_id=setsid();
		printf("Session_id= %d \n",session_id);
		chdir("/");
		umask(0);
		time(&rawtime);
		time_info=localtime(&rawtime);
		while(time_info->tm_hour==11 && time_info->tm_min<16){
			sleep(10);
			time(&rawtime);
			time_info=localtime(&rawtime);
		}
		if(time_info->tm_hour==11 && time_info->tm_min==16){
		system("sh /home/shubham/Desktop/SS/Software_System/Q30/demo.sh");
		printf("Job Completed");
	        }
	}else{
		printf("Parent Process");
	}
}
