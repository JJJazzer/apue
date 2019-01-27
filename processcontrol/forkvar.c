/*
 * file name: forkvar.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sun 27 Jan 2019 10:25:01 AM CST
 */

#include <apue.h>

int globlvar = 6;

char buf[] = "A write to stdout\n";

int main(void)
{
	int var;
	pid_t pid;

	var = 88;

	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != 
			sizeof(buf) - 1)
		err_sys("write error");
	printf("before fork\n");

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		globlvar++;
		var++;
		printf("I'm child process my parent = %ld, pid = %ld, globl = %d,"
				"var = %d\n", 
			(long) getppid(),(long)getpid(), globlvar, var);
	} else {
		sleep(2); 
		printf("I'm parent process my parent = %ld, pid = %ld, globl = %d,"
				"var = %d\n", 
			(long) getppid(),(long)getpid(), globlvar, var);
	}

	exit(0);
}
