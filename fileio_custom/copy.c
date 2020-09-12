#include <sys/stat.h>
#include <fcntl.h>
#include "../tlpi-dist/lib/tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[]){
	
	int inputFd, outputFd, openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];

	if(argc != 3 || strcmp(argv[1], "-help") ==0 )
		usageErr("%s src_file dest_file \n" , argv[0]);

	/* Open inpput and output files */

	inputFd = open(argv[1], O_RDONLY);
	if(inputFd == -1)
		errExit("Opening File %s", argv[1]);

	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	// printf("Debug: openFlags: %d \n",openFlags);

	filePerms = S_IRUSR | S_IWUSR| S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; // rw-rw-rw-
	// printf("Debug: filePerms: %d \n",filePerms);	

	outputFd = open(argv[2], openFlags, filePerms);
	if (outputFd == -1)
		errExit("opening file %s", argv[2]);

	while((numRead = read(inputFd, buf, BUF_SIZE)) > 0){
		if(write(outputFd,buf,BUF_SIZE) != numRead)
            fatal("write() returned error or partial write occurred");
	}

	if (numRead == -1)
		errExit("read");

	if(close(inputFd) == -1)
		errExit("close input");
	
	if(close(outputFd) == -1)
		errExit("close output");

	exit(EXIT_SUCCESS);
}