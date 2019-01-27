/*
 * file name: complete.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sun 27 Jan 2019 11:07:06 AM CST
 */

#include <apue.h>

static void charatatime(char *str);

int main(void)
{
	pid_t pid;
	
	TELL_WAIT();
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		WAIT_PARENT();
		charatatime("Out from child\n");
	} else {
		charatatime("Out from parent\n");
		TELL_CHILD(pid);
	}
	exit(0);
}

static void charatatime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout, NULL);
	for (ptr = str; (c = *ptr++) != '\0';)
		putc(c, stdout);
}
