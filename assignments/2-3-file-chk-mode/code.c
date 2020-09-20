#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]){

	int mode = 0;
	if(argc <=2 || argc > 3 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-H") == 0 ){
		usageErr("%s <file-to-open> <>\n" , argv[0]);
	}

	if(strcmp(argv[2],"read") == 0)
		mode = R_OK;
	else if(strcmp(argv[2],"write") == 0)
		mode = W_OK;
	else if(strcmp(argv[2],"execute") == 0)
		mode = E_OK;
	else{
		printf("Invalid Arguments");
		return -1;
	}


	if(access(argv[1], mode) < 0)
		printf("Process cannot open file for %s purpose  \n", argv[2]);

	close(fd);
	return 0;
}