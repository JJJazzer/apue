/*
 * file name: pread.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 06:12:38 PM CST
 */

#include <apue.h>
#include <fcntl.h>

#define BUFSIZE		4096

int main(void)
{
	int fd, fd2;
	int n = 0;
	char buf[BUFSIZE];
	char *s = "hello";
	int len = strlen(s);
	if ((fd = open("./file.seek", O_CREAT | O_RDWR, 0644)) < 0)
		err_sys("Create file error");
	if ((fd2 = open("./file.seek.write", O_CREAT | O_RDWR, 0644)) < 0)
		err_sys("Create file error");
	if (write(fd, s, len) != len)
		err_sys("write error");

	while ((n = pread(fd, buf, BUFSIZE, n)) != 0) { 
		printf("%d\n", n);
		if (pwrite(fd2, buf, n, 0) != n)
			err_sys("Write error");
	}
	if (n < 0)
		err_sys("Read error");
	exit(0);
}
