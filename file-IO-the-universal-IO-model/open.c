#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include"tlpi_hdr.h"


main()
{
	int fd;

	if((fd = open("a.txt",O_RDONLY)) == -1){
		errExit("open");
	}

	fd = open("myfile", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if(fd == -1)
		errExit("open");

	fd = open("w.log",  O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);

	if(fd == -1)
		errExit("open");

	if(close(STDIN_FILENO) == -1)
		errExit("close");

	fd = open("w.log", O_RDONLY);
	if(fd == -1)
		errExit("open");
	else
		printf("\n%d\n",fd);
}
