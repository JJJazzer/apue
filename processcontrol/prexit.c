/*
 * file name: prexit.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sun 27 Jan 2019 10:40:10 AM CST
 */
#include <apue.h>
#include <sys/wait.h>
#include <fcntl.h>

void pr_exit(int status);

int main(void)
{
	pid_t pid;
	int status;
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		exit(7);
	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
	
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		abort();
	if (wait(&status) != pid)
		err_sys("Wait error");
	pr_exit(status);
	

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		status /= 0;
	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
	
	return 0;
}

void pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("Normal termination, exit status=%d\n",
				WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("Abnormal termination, signal number=%d%s\n",
				WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status) ? " (core dump)" : "");
#else 
			"");
#endif
	else if (WIFSTOPPED(status))
		printf("Child stopped, signal number=%d\n",
				WSTOPSIG(status));
}
