/*
 * file name: gethosinfo.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 25 Jan 2019 09:15:01 AM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <apue.h>
#include <unistd.h>

#define BUFSIZE 	4096

int main(void)
{
	struct utsname um;
	char name[BUFSIZE];
	if (uname(&um) == -1) {
		err_sys("Uname error");	
	}
	printf("%s %s %s %s %s\n", um.sysname, um.nodename,
			um.release, um.version, um.machine);
	if (gethostname(name, BUFSIZE) == -1)
		err_sys("gethostname error");
	printf("%s\n", name);
	exit(0);
}
