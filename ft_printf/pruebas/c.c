#include <unistd.h>
#include <stdio.h>
#include "../libftprintf.h"

int main()
{
	for (int i = 0; i < 256; ++i)
	{
		printf("%c", i);
	}
	printf("\n");
	for (int i = 0; i < 256; ++i)
	{
		ft_putchar(i);
	}
	printf("\n");
	for (int i = 32; i < 127; ++i)
	{
		printf("%c", i);
	}
	printf("\n");
	for (int i = 32; i < 127; ++i)
	{
		ft_putchar(i);
	}
	printf("\n");

	printf("Case #1:\n");
	printf("printf: %c\n", 2147483647);
	ft_putchar(2147483647);
	printf("\n");

	printf("Case #2:\n");
	printf("printf: %c\n", (int)-2147483648);
	ft_putchar(-2147483648);
	printf("\n");

	printf("Case #3:\n");
	printf("printf: %c\n", 578);
	ft_putchar(578);
	printf("\n");
}
