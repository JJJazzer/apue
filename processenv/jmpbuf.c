/*
 * file name: jmpbuf.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 26 Jan 2019 09:00:55 AM CST
 */

#include <apue.h>
#include <setjmp.h>

jmp_buf jmpbuffer;

void test_fun1();
void test_fun2();
int main(void)
{
	int ret;
	if ((ret = setjmp(jmpbuffer)) != 0)
		printf("%d\n", ret);	
	if (ret == 0)
		test_fun2();
	else if (ret == 1)
		test_fun1();
	return 0;
}

void test_fun1()
{
	printf("Go to test_fun1\n");
}

void test_fun2()
{
	longjmp(jmpbuffer, 1);
}
