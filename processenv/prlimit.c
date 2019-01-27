/*
 * file name: prlimit.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 26 Jan 2019 09:17:25 AM CST
 */

#include <apue.h>
#include <sys/resource.h>

#define doit(name) 	pr_limits(#name, name)

static void pr_limits(char *, int);

int main(void)
{
#ifndef RLIMIT_AS
	doit(RLIMIT_AS);
#endif
	doit(RLIMIT_CORE);
	doit(RLIMIT_CPU);
	doit(RLIMIT_DATA);
	doit(RLIMIT_FSIZE);
	exit(0);
}

static void pr_limits(char *name, int resource)
{
	struct rlimit limit;
	unsigned long long lim;

	if (getrlimit(resource, &limit) < 0)
		err_sys("getrlimit error for %s", name);
	printf("%-14s ", name);
	if (limit.rlim_cur == RLIM_INFINITY) {
		printf("(infinite) ");
	} else {
		lim = limit.rlim_cur;
		printf("%10lld ", lim);
	}

	if (limit.rlim_max == RLIM_INFINITY) {
		printf("(infinite) ");
	} else {
		lim = limit.rlim_max;
		printf("%10lld ", lim);
	}
	putchar('\n');
}
