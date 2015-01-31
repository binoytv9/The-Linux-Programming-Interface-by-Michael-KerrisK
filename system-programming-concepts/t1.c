main()
{
	int fd;

	fd = open(pathname, flags, mode);
	if(fd == 1)
		printf("\nerror\n");

	if(close(fd) == -1)
		printf("\nerror in closing\n");
}
