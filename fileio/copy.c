/*
 * file name: copy.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 06:03:07 PM CST
 */

#include <apue.h>

#define BUFFSIZE 	4096

int main(void)
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("Write error");
	if (n < 0)
		err_sys("read error");
	exit(0);
}
