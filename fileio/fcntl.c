/*
 * file name: fcntl.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 09:43:23 PM CST
 */

#include <apue.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int val;

	if (argc != 2)
		err_quit("Usage: fcntl <descriptor#>");
	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		err_sys("fcntl error for fd %d", atoi(argv[1]));

	switch (val & O_ACCMODE) {
	case O_RDONLY:
		printf("read only");
		break;
	case O_WRONLY:
		printf("write only");
		break;
	case O_RDWR:
		printf("read and write");
		break;
	default:
		err_dump("Unknown access mode");
	}
	if (val & O_APPEND)
		printf(", append");
	if (val & O_NONBLOCK)
		printf(", nonblocking");
	if (val & O_SYNC)
		printf(", synchronous writes");
	putchar('\n');
	exit(0);
}
