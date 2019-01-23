/*
 * file name: hole.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 05:56:50 PM CST
 */

#include <apue.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;
	if ((fd = creat("file.hole", FILE_MODE)) < 0)
		err_sys("create error");
	if (write(fd, buf1, 10) != 10)
		err_sys("buf1 write error");
	if (lseek(fd, 16384, SEEK_SET) == -1)
		err_sys("lseek error");

	if (write(fd, buf2, 10) != 10)
		err_sys("buf2 write error");
	/* file.hole with hole, it only have 8 disk block,
	 * but file.nohole have 20 disk block.
	 * Please use command "ls -ls" to view them.
	 */
	exit(0);
}
