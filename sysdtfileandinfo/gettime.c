/*
 * file name: gettime.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 25 Jan 2019 09:22:15 AM CST
 */

#include <time.h>
#include <apue.h>
#include <sys/time.h>

int main(void)
{
	time_t tm;
	struct timespec tmsp;
	struct timeval tmval;
	tm = time(&tm);
	printf("%ld\n%ld\n", tm, time(NULL));
	if (clock_gettime(CLOCK_REALTIME, &tmsp) == -1)
		err_sys("clock_gettime error");
	printf("second: %ld nanosec: %ld\n", tmsp.tv_sec, tmsp.tv_nsec);
	clock_getres(CLOCK_REALTIME_COARSE, &tmsp);
	printf("second: %ld nanosec: %ld\n", tmsp.tv_sec, tmsp.tv_nsec);
	gettimeofday(&tmval, NULL);
	printf("second: %ld usec: %ld\n", tmval.tv_sec, tmval.tv_usec);
	return 0;
}
