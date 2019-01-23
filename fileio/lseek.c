/*
 * file name: lseek.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 05:54:02 PM CST
 */

#include <apue.h>

int main(void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("Can't seek\n");
	else
		printf("Seek successful\n");
	exit(0);
}
