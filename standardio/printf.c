/*
 * file name: printf.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 24 Jan 2019 09:35:32 AM CST
 */

#include <apue.h>
#include <fcntl.h>

int main(void)
{
	/* dprintf */
	int fd;
	char buf[4096];
	if ((fd = open("foo", O_RDWR)) < 0)
		err_sys("Open error");
	dprintf(fd, "Hello %s\n", "World");
	sprintf(buf, "hello %s\n", "World");
	printf("%s\n", buf);

	exit(0);
}
