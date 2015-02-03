#include<stdio.h>
#include<fcntl.h>
#include"tlpi_hdr.h"

main(int argc, char *argv[])
{
	int ap;
	int flags;
	mode_t mode;

	printf("\nargc = %d\n",argc);
	if(argc > 3 || (argc > 1 && strcmp(argv[1],"--help") == 0))
		usageErr("%s [-a] [filename]\nCopy standard input to the file, and also to standard output.\n  -a,\tappend to the given file, do not overwrite\n",argv[0]);

	
	for(ap = 0; ap < argc; ap++){
		if(argv[ap][0] == '-')
			switch(argv[ap][1]){
				case 'a':
					flags = O_WRONLY | O_CREAT | O_APPEND;
					mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
					break;
				default:
					cmdLineErr("invalid option -%c\n",argv[ap][1]);
					break;
			}
		else{
			
	}
}
