#include<stdio.h>
#include"tlpi_hdr.h"
#include<fcntl.h>

main()
{
	int fd;

	if((fd = creat("w.log",S_IRUSR)) == -1)
		errExit("creat");
}
