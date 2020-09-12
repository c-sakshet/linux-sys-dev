#include<stdio.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]){
	
	if(argc < 2 || argc >= 3 || strcmp(argv[1], "-help") ==0 || strcmp(argv[1], "-h") ==0 || strcmp(argv[1], "-H") ==0){
		printf("Usage %s <enter_name_to_print>\n", argv[0]);
		exit(-1);
	}

	printf("%s \n", argv[1]);

	return 0;
}