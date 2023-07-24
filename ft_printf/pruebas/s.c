#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s1[] = "Hola Mundo\nSoy programador";
	char *s2 = "Hola Mundo\nSoy programador";
	char *s3;
	s3 = malloc(100*sizeof(char));

	printf("Case #1:\n");
	printf("printf: %s\n", s1);
	//ft_printf("ft_printf: %d\n", 180);

	printf("Case #2:\n");
	printf("printf: %s\n", s2);
	//ft_printf("ft_printf: %d\n", 180);

	printf("Case #3:\n");
	printf("printf: %s\n", s3);
	//ft_printf("ft_printf: %d\n", 180);
}
