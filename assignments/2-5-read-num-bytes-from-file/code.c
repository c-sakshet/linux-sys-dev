#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]){
	// char arr[11];
	// char brr[4];
	// char crr[4];
	// int ret;

	char rdbuf[100000];
	int buf = 0;
	if(argc <= 2 || argc > 3 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-H") == 0 ){
		usageErr("%s <file-to-open> <number of bytes to read>ss \n" , argv[0]);
	}

	buf = atoi(argv[2]);
	// If buf exceeds rdbuf limit, expect SIGABORT to exit and return stack smashing error
	int ret = 0;
	int fd = open(argv[1], O_RDONLY);
	
	if (fd == -1){
		errExit("Error opening file %s\n", argv[1]);
	}

	ret = read(fd, rdbuf, buf);
	write(1, rdbuf, buf);  // 1 is stdout, so it prints to cmdline

	return 0;
}