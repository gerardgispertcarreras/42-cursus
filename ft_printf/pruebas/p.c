#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libftprintf.h"

int main()
{
	int a = 300;
	char c = 'j';
	void *p;
	p = malloc(100*sizeof(int));

	printf("Case #1:\n");
	printf("printf: %p\n", &a);
	p_format(&a);
	
	printf("Case #2:\n");
	printf("printf: %p\n", &c);
	p_format(&c);
	
	printf("Case #3:\n");
	printf("printf: %p\n", p);
	printf("printf: %p\n", &p);
	p_format(&p);
}