#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]){

	int mode = 0;
	if(argc <=2 || argc > 3 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-H") == 0 ){
		usageErr("%s <file-to-open> <>\n" , argv[0]);
	}

	if(strcmp(argv[2],"read") == 0)
		mode = O_RDONLY;
	else if(strcmp(argv[2],"write") == 0)
		mode = O_WRONLY;
	else if(strcmp(argv[2],"read-write") == 0)
		mode = O_RDWR;
	else if(strcmp(argv[2],"create") == 0)
		mode = O_CREAT;
	else if(strcmp(argv[2],"truncate") == 0)
		mode = O_WRONLY | O_WRONLY;
	else{
		printf("Invalid Arguments");
		return -1;
	}



	int fd = open(argv[1], mode);
	if (fd == -1){
		errExit("Error opening file %s\n", argv[1]);
	}

	printf("\"%s\" file opened with FD = %d \n", argv[1], fd);

	close(fd);
	return 0;
}