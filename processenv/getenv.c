/*
 * file name: env.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 26 Jan 2019 08:41:54 AM CST
 */

#include <apue.h>

int main(void)
{
	char *value;
	value = getenv("HOME");
	printf("%s\n", value);
	if (putenv("MAILPATH=/var/mail") != 0)
		err_sys("putenv error");
	value = getenv("MAILPATH");
	printf("%s\n", value);
	char *name = (char*) malloc(20 * sizeof(char));
	name = "MAILPATH";
	value = (char*) malloc(sizeof(char) * 20);
	value = "/var/mail/nobody";
	if (setenv(name, value, 1) == -1)
		err_sys("setenv error");
	value = getenv("MAILPATH");
	printf("%s\n", value);
	name = NULL;
	value = NULL;
	free(name);
	free(value);
	return 0;
}
