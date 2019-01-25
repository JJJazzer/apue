/*
 * file name: groups.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 25 Jan 2019 09:04:15 AM CST
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	gid_t gplist[30];
	int i;
	int ret = getgroups(0, gplist);
	if (ret == -1) {
		fprintf(stderr, "getgroups error\n");
		exit(-1);
	}
	getgroups(ret, gplist);
	for (i = 0; i < ret; i++)
		printf("%d: %d\n", i, gplist[i]);
	return 0;
}
