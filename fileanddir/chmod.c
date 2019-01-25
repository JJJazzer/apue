/*
 * file name: chmod.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 24 Jan 2019 08:20:40 AM CST
 */

#include <apue.h>

int main(void)
{
	struct stat statbuf;

	if (stat("foo.bar", &statbuf) < 0)
		err_sys("stat error");
	if (chmod("foo.bar", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		err_sys("chmod error for foo");
	if (chmod("bar.foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		err_sys("chmod error for bar");
	exit(0);
}
