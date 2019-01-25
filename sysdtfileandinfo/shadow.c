/*
 * file name: shadow.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 25 Jan 2019 08:50:51 AM CST
 */

#include <stdio.h>
#include <shadow.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#define USER	"hanwnz"

struct spwd *getspnam(const char *name)
{
	struct spwd *ptr;
	setspent();
	while ((ptr = getspent()) != NULL)
		if (strcmp(name, ptr->sp_namp) == 0)
			break;
	endspent();
	return ptr;
}
int main(void)
{
	struct spwd *ptr;
	ptr = getspnam("hanwnz");
	printf("%s %s\n%ld %ld\n", ptr->sp_namp, ptr->sp_pwdp,
			ptr->sp_warn, ptr->sp_expire);
	return 0;

}
