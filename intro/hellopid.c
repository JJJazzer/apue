/*
 * file name: hellopid.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 05:04:54 PM CST
 */

#include <apue.h>

int main(void)
{
	printf("Hello, this process ID is %ld\n", (long) getpid());
	exit(0);
}
