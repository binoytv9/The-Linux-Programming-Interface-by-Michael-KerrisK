#include<stdio.h>
#include<fcntl.h>
#include"tlpi_hdr.h"

#define MAX_READ 100

main(int argc, char *argv[])
{
	int ap;
	int flags;
	mode_t mode;
	int fd = -1;

	ssize_t numRead;
	ssize_t numWritten;
	char buffer[MAX_READ+1];

	if(argc > 3 || (argc > 1 && strcmp(argv[1],"--help") == 0))
		usageErr("%s [-a] [filename]\nCopy standard input to the file, and also to standard output.\n  -a,\tappend to the given file, do not overwrite\n",argv[0]);

	if(*++argv){
		--argc;
		flags = O_WRONLY | O_CREAT | O_TRUNC;
		mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

		/* option start wit '-' */	
		if((*argv)[0] == '-'){
			switch((*argv)[1]){
				case 'a':
					flags = O_WRONLY | O_CREAT | O_APPEND;
					break;
				default:
					cmdLineErr("invalid option -%c\n",argv[ap][1]);
					break;
			}
			++argv;
			--argc;
		}

		if(argc){
			fd = open(*argv, flags, mode);
			if(fd == -1)
				errExit("open");
		}
	}

	while((numRead = read(STDIN_FILENO, buffer, MAX_READ)) > 0){
		buffer[numRead] = '\0';
		numWritten = write(STDOUT_FILENO, buffer, numRead);
		if(numWritten == -1)
			errExit("write to stdout");

		if(fd != -1)
			write(fd, buffer, numRead);
		if(numWritten == -1)
			errExit("write to %s",*argv);
	}
	if(numRead == -1)
		errExit("read from stdin");

	if(fd != -1)
		if(close(fd) == -1)
			errExit("close");
		
}
