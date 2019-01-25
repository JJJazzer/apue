/*
 * file name: strftime.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 25 Jan 2019 09:41:45 AM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t t;
	struct tm *tmp, tmp2;
	char buf1[16];
	char buf2[64];

	time(&t);
	tmp = localtime(&t);
	if (strftime(buf1, 16, "time and date: %r, %a, %b, %d, %Y", tmp)
			== 0)
		printf("buffer length 16 is too small\n");
	else
		printf("%s\n", buf1);
	if (strftime(buf2, 64, "time and date: %r, %a, %b, %d, %Y", tmp)
			== 0)
		printf("buffer length 64 is too small\n");
	else
		printf("%s\n", buf2);
	if (strptime(buf2, "time and date: %r, %a, %b, %d, %Y",
				&tmp2) != NULL)
		printf("%d:%d\n", tmp2.tm_hour, tmp2.tm_min);
	return 0;
}
