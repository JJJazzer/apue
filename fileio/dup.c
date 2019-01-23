/*
 * file name: dup.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 06:43:07 PM CST
 */

#include <apue.h>
#include <fcntl.h>

int main(void)
{
	int fd1, fd2, fd3;
	char buf[MAXLINE];
	int n;
	if ((fd1 = open("file.seek", O_RDWR)) < 0)
		err_sys("Open error");
	fd2 = dup(fd1);
	while ((n = read(fd2, buf, MAXLINE)) > 0) 
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("Write error");
	if (n < 0)
		err_sys("Read error");
	
	lseek(fd2, 0, SEEK_SET); 
	fd3 = fcntl(fd2, F_DUPFD, 0);
	while ((n = read(fd3, buf, MAXLINE)) > 0) 
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("Write error");
	close(fd3);

	exit(0);
}
