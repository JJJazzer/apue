/*
 * file name: system.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sun 27 Jan 2019 03:08:46 PM CST
 */

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <apue.h>

int system(const char *cmdline)
{
	pid_t pid;
	int status;

	if (cmdline == NULL)
		return 1;

	if ((pid = fork()) < 0) {
		status = -1;
	} else if (pid == 0) {
		execl("/bin/sh", "sh", "-c", cmdline, (char*) 0);
		exit(127);
	} else {
		while (waitpid(pid, &status, 0) < 0) {
			if (errno != EINTR) {
				status = -1;
				break;
			}
		}
	}
	return status;
}
