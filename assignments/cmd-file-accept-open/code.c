#include<stdio.h>
#include<fcntl.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]){
	// char arr[11];
	// char brr[4];
	// char crr[4];
	// int ret;
	if(argc == 1 || argc > 2 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-H") == 0 ){
		usageErr("%s <file-to-open> \n" , argv[0]);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1){
		errExit("Error opening file %s\n", argv[1]);
	}

	printf("\"%s\" file opened with FD = %d\t\n", argv[1], fd);

	// ret = read(fd, arr, 10);
	// printf("%s\n", arr);

	// ret = read(fd, brr, 4);
	// printf("%s\n", brr);

	// ret = read(fd, crr, 4);
	// printf("%s\n", crr);

	return 0;
}