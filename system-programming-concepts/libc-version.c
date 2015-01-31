#include<stdio.h>
#include<gnu/libc-version.h>

main()
{
	printf("version of glibc is : %s\n\n",gnu_get_libc_version());
}
