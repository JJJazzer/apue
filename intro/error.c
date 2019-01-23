/*
 * file name: error.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 05:13:22 PM CST
 */

#include <apue.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int i;
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	/* base errno only 34 */
	for (i = 0; i < 34; i++) {
		errno = i;
		perror(argv[0]);
	}
	exit(0);
}
