/*
 * file name: umask.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 24 Jan 2019 08:13:30 AM CST
 */

#include <apue.h>
#include <fcntl.h>

#define RWRWRW 	(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
	umask(0);
	if (creat("foo.bar", RWRWRW) < 0)
		err_sys("create error");
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (creat("bar.foo", RWRWRW) < 0)
		err_sys("create error");
	exit(0);
}
