/*
 * file name: tmpname.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 24 Jan 2019 11:46:46 AM CST
 */

#include <apue.h>

int main(void)
{
	char name[L_tmpnam], line[MAXLINE];

	FILE *fp;

	printf("%s\n", tmpnam(NULL));
	tmpnam(name);
	printf("%s\n", name);

	if ((fp = tmpfile()) == NULL)
		err_sys("tmpfile error");
	fputs("one line of output\n", fp);
	rewind(fp);
	rewind(fp);
	if (fgets(line, sizeof(line), fp) == NULL)
		err_sys("fgets error");
	fputs(line, stdout);
	exit(0);
}
