

#include<stdio.h>
#include<fcntl.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]){

	if(argc == 1 || argc > 2 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-H") == 0 ){
		usageErr("%s <file-to-open> \n" , argv[0]);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1){
		errExit("Error opening file %s\n", argv[1]);
	}

	printf("\"%s\" file opened with FD = %d\n", argv[1], fd);

	return 0;
}