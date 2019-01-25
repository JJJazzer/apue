/*
 * file name: faccess.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 24 Jan 2019 08:09:59 AM CST
 */

#include <apue.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
		err_quit("Usage: faccess <pathname>");
	if (access(argv[1], R_OK) < 0)
		err_ret("access error for %s", argv[1]);
	else
		printf("read access OK\n");
	if (open(argv[1], O_RDONLY) < 0)
		err_ret("open error for %s", argv[1]);
	else
		printf("open for reading OK\n");
	exit(0);
}
