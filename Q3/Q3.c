#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd;
	fd=creat("text.txt",O_RDONLY|O_WRONLY);
	printf("fd = %d",fd);
	if(fd==-1){
		printf("File Already exist");
	}
}
