echo '#include<stdio.h>\nmain()\n{\n}' > myprog.c
cc myprog.c -o myprog
ldd myprog | grep libc
