/*
 * file name: shll1.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 05:06:24 PM CST
 */

#include <apue.h>
#include <sys/wait.h>

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		int len = strlen(buf);
		if (buf[len - 1] == '\n')
			buf[len - 1] = '\0';

		if ((pid = fork()) < 0) {
			err_sys("fork error");
		} else if (pid == 0) {
			execlp(buf, buf, (char*) 0);
			err_ret("Can't execute: %s", buf);
			exit(127);
		} 

		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}
