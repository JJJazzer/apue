/*
 * file name: getpwnam.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 25 Jan 2019 08:43:03 AM CST
 */

#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

struct passwd *getpwnam(const char *name)
{
	struct passwd *ptr;

	setpwent();

	while ((ptr = getpwent()) != NULL) 
		if (strcmp(name, ptr->pw_name) == 0)
			break;
	endpwent();
	return ptr;
}

int main(void)
{
	struct passwd *p;
	p = getpwnam("hanwnz");
	printf("%s %d %d %s\n%s %s %s\n", p->pw_name, p->pw_uid, p->pw_gid,
			p->pw_dir, p->pw_shell, p->pw_passwd, p->pw_gecos);
	return 0;
}
