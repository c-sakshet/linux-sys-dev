#include <stdio.h> 
#include <dirent.h> 
#include <string.h>
// #include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char* argv[]) 
{ 
    struct dirent *ent;  // Pointer for directory entry 
	
	if(argc == 1 || argc > 3 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-H") == 0 ){
		printf("%s <file-to-open> \n" , argv[0]);
	}

    DIR *d = opendir(argv[1]); // returns a pointer of DIR type.  
  
    if (d == NULL)  // returns NULL if d fails 
    { 
		printf("Error opening folder %s\n", argv[1]);
        return 0; 
    } 
 
    while ((ent = readdir(d)) != NULL) 
            printf("%s\n", ent->d_name); 
  
    closedir(d);

    return 0; 
}