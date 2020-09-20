#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]){

	int ret, fd;
	struct stat fileStat;
	
	if(argc != 2 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-H") == 0 ){
		usageErr("%s <file-to-open> <>\n" , argv[0]);
	}


	ret = stat(argv[1], &fileStat);
	if (ret == -1)
		errExit("Unable to open file\n");
	
	printf("File Size: \t %d bytes \n", (int)fileStat.st_size);
	printf("No of links: \t %d \n", (int)fileStat.st_nlink);
	printf("File Inode Number: \t %d \n", (int)fileStat.st_ino);
	printf("File System Number: \t %d \n", (int)fileStat.st_dev);
	printf("No of blocks allocated for file: \t %d \n", (int)fileStat.st_blocks);
	printf("File Permissions: \t\n");


	printf( (S_ISDIR(fileStat.st_mode))? "d" : "-");
	printf( (fileStat.st_mode & S_IRUSR)? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR)? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR)? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP)? "r" : "-");
	printf( (fileStat.st_mode & S_IRGRP)? "w" : "-");
	printf( (fileStat.st_mode & S_IRGRP)? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH)? "r" : "-");
	printf( (fileStat.st_mode & S_IROTH)? "w" : "-");
	printf( (fileStat.st_mode & S_IROTH)? "x\n" : "-\n");

	if(S_ISLNK(fileStat.st_mode))
		printf("\nFile is Symbolic link\n");
	else
		printf("File is not a Symbolic link\n");

	close(fd);
	return 0;
}