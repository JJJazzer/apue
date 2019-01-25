/*
 * file name: copy2.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 24 Jan 2019 08:52:59 AM CST
 */

#include <apue.h>

#define MAXBUF 		4096

int main(void)
{
	char buf[MAXBUF];
	while (fgets(buf, MAXBUF, stdin) != NULL)
		if (fputs(buf, stdout) == EOF)
			err_sys("output error");
	if (ferror(stdin))
		err_sys("input error");
	exit(0);
}
