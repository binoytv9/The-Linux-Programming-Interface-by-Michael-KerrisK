#include<stdio.h>
#include"tlpi_hdr.h"

#define MAX_READ 100

main()
{
	char buffer[] = "(char *)malloc(MAX_READ+1)";

	ssize_t numWrite;

	if((numWrite = write(STDOUT_FILENO, buffer, sizeof(buffer))) == -1)
		errExit("read");

	printf("\nnumWrite : %ld\n",numWrite);
}
