#include <stdio.h> 
#include <dirent.h> 
#include <sys/stat.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]) 
{ 
    struct dirent *de;  // Pointer for directory entry 
    struct stat filestat;

	if(argc == 1 || argc > 3 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-H") == 0 ){
		printf("%s <file-to-open> \n" , argv[0]);
	}

    DIR *dr = opendir(argv[1]); 

    // opendir() returns a pointer of DIR type.  
  
    if (dr == NULL)  // returns NULL if dir fails 
    { 
		printf("Error opening folder %s\n", argv[1]);
        return 0; 
    } 
 
    while ((de = readdir(dr)))
        {   
            if(de->d_type ==4)
                printf("%4s  -   %s \n", "Dir",  de->d_name); 
            else
                printf("%4s  -   %s \n", "File", de->d_name); 
        }
    closedir(dr);

    return 0; 
}