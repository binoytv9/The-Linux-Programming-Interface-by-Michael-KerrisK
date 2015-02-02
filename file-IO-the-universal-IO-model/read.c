#include<stdio.h>
#include"tlpi_hdr.h"

#define MAX_READ 100

main()
{
	char *buffer = (char *)malloc(MAX_READ+1);

	ssize_t numRead;

	if((numRead = read(STDIN_FILENO, buffer, MAX_READ)) == -1)
		errExit("read");

	buffer[numRead] = '\0';
	printf("The input data was : %s\n",buffer);
}
