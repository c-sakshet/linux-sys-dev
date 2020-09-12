#include<stdio.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]){
	
	if(argc >=2){
		printf("Usage: %s \n", argv[0]);
		exit(-1);
	}

	printf("Hello World!\n");

	return 0;
}