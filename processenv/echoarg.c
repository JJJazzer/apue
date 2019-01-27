/*
 * file name: echoarg.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 26 Jan 2019 08:32:17 AM CST
 */

#include <apue.h>

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	exit(0);
}
