/*
 * file name: fread.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 24 Jan 2019 09:16:58 AM CST
 */

#include <apue.h>

#define MAXBUF 		4096

int main(void)
{
	char *buf = "Hello\n";
	char buff[MAXBUF];
	int n;
	FILE *fp;
	if ((fp = fopen("foo", "a+")) == NULL)
		err_sys("Fopen error");
	if (fwrite(buf, sizeof(char), strlen(buf), fp) != strlen(buf))
		err_sys("Fwrite error");
	if (fseek(fp, 0, SEEK_SET) == -1)
		err_sys("Seek error");
	while ((n = fread(buff, sizeof(char), MAXBUF, fp)) > 0)
		if (fwrite(buff, sizeof(char), strlen(buff), stdout) != strlen(buff))
			err_sys("Write error");
	exit(0);
}
