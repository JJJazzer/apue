/*
 * file name: ls2.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 23 Jan 2019 03:04:30 PM CST
 */

#define _DEFAULT_SOURCE

#include <apue.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR 	*dp;
	struct dirent *dirp;
	
	if (argc != 2)
		err_quit("Usage: ls <directory>");
	if ((dp = opendir(argv[1])) == NULL)
		err_sys("Open %s error", argv[1]);
	while ((dirp = readdir(dp)) != NULL) {
		printf("%-30s\t%d\t\t", dirp->d_name,
				dirp->d_reclen);
		switch (dirp->d_type) {
		case DT_BLK:
			printf("%s\n", "block device");
			break;
		case DT_CHR:
			printf("%s\n", "char device");
			break;
		case DT_DIR:
			printf("%s\n", "directory");
			break;
		case DT_REG:
			printf("%s\n", "regular file");
			break;
		case DT_SOCK:
			printf("%s\n", "socket file");
			break;
		case DT_FIFO:
			printf("%s\n", "fifo file");
			break;
		case DT_LNK:
			printf("%s\n", "link file");
			break;
		case DT_UNKNOWN:
			printf("%s\n", "unknown file");
			break;
		}
	}
	closedir(dp);
	exit(0);
}
