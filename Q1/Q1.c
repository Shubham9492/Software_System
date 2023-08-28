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
