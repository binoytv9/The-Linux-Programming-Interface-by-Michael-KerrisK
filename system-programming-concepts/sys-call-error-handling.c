#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

main()
{
	int cnt;
	int fd = 0;
	char buf[10];
	int flags = 0;
	char mode[] = "r";
	char pathname[] = "t.c";
	int numbytes = sizeof(buf);

	fd = open(pathname, flags, mode);
	if(fd == -1)
		printf("\nerror\n");
	else
		printf("\nsuccess\n");

	/* using strerror() */
	fprintf(stderr,"error string using strerror() : %s\n",strerror(errno));


	/* using perror() */
	if(fd == -1){
		perror("open");
		fprintf(stderr,"exit failure is %d\n",EXIT_FAILURE);
		fprintf(stderr,"error number is %d\n",errno);
		exit(EXIT_FAILURE);
	}

	cnt = read(fd, buf, numbytes);
	if(cnt == -1){
		if(errno == EINTR)
			fprintf(stderr,"read was interrupted by a signal\n");
		else
			fprintf(stderr,"error number is %d\n",errno);
	}

	if(close(fd) == -1)
		printf("\nerror in closing\n");
}
