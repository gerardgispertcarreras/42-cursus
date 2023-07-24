#include <unistd.h>
#include <stdio.h>
#include "../libftprintf.h"

int main()
{
	char c = 'u';
	if (c == 'd')
	{
		printf("Case #1:\n");
		printf("printf: %d\n", 180);
		ft_putint(180);
		printf("\n");

		printf("Case #2:\n");
		printf("printf: %d\n", -492);
		ft_putint(-492);
		printf("\n");

		printf("Case #3:\n");
		printf("printf: %d\n", 2147483647);
		ft_putint(2147483647);
		printf("\n");

		printf("Case #4:\n");
		printf("printf: %d\n", (int)-2147483648);
		ft_putint((int)-2147483648);
		printf("\n");

		printf("Case #5:\n");
		printf("printf: %d\n", (int)2147483648);
		ft_putint((int)2147483648);
		printf("\n");

		printf("Case #5:\n");
		printf("printf: %d\n", (int)-2147483649);
		ft_putint((int)-2147483649);
		printf("\n");

		printf("Case #6:\n");
		printf("printf: %d\n", +1);
		ft_putint(+1);
		printf("\n");

		printf("Case #7:\n");
		printf("printf: %d\n", 021);
		ft_putint(021);
		printf("\n");

		printf("Case #8:\n");
		printf("printf: %d\n", 0021);
		ft_putint(000021);
		printf("\n");

		printf("Case #9:\n");
		printf("printf: %d\n", 0x2A1);
		ft_putint(0x2A1);
		printf("\n");

		printf("Case #10:\n");
		printf("printf: %d\n", 0x2a1);
		ft_putint(0x2a1);
		printf("\n");

		printf("Case #11:\n");
		printf("printf: %d\n", 0X2a1);
		ft_putint(0X2a1);
		printf("\n");
	}
	else if (c == 'i')
	{
		printf("Case #1:\n");
		printf("printf: %i\n", 180);
		ft_putint(180);
		printf("\n");

		printf("Case #2:\n");
		printf("printf: %i\n", -492);
		ft_putint(-492);
		printf("\n");

		printf("Case #3:\n");
		printf("printf: %i\n", 2147483647);
		ft_putint(2147483647);
		printf("\n");

		printf("Case #4:\n");
		printf("printf: %i\n", (int)-2147483648);
		ft_putint((int)-2147483648);
		printf("\n");

		printf("Case #5:\n");
		printf("printf: %i\n", (int)2147483648);
		ft_putint((int)2147483648);
		printf("\n");

		printf("Case #5:\n");
		printf("printf: %i\n", (int)-2147483649);
		ft_putint((int)-2147483649);
		printf("\n");

		printf("Case #6:\n");
		printf("printf: %i\n", +1);
		ft_putint(+1);
		printf("\n");

		printf("Case #7:\n");
		printf("printf: %i\n", 021);
		ft_putint(021);
		printf("\n");

		printf("Case #8:\n");
		printf("printf: %i\n", 0021);
		ft_putint(000021);
		printf("\n");

		printf("Case #9:\n");
		printf("printf: %i\n", 0x2A1);
		ft_putint(0x2A1);
		printf("\n");

		printf("Case #10:\n");
		printf("printf: %i\n", 0x2a1);
		ft_putint(0x2a1);
		printf("\n");

		printf("Case #11:\n");
		printf("printf: %i\n", 0X2a1);
		ft_putint(0X2a1);
		printf("\n");
	}
	else if (c == 'u')
	{
		printf("Case #1:\n");
		printf("printf: %u\n", (unsigned int)180);
		ft_putint((unsigned int)180);
		printf("\n");

		printf("Case #2:\n");
		printf("printf: %u\n", (unsigned int)-492);
		ft_putint((unsigned int)-492);
		printf("\n");

		printf("Case #3:\n");
		printf("printf: %u\n", (unsigned int)2147483647);
		ft_putint((unsigned int)2147483647);
		printf("\n");

		printf("Case #4:\n");
		printf("printf: %u\n", (unsigned int)4294967295);
		ft_putint((unsigned int)4294967295);
		printf("\n");

		printf("Case #6:\n");
		printf("printf: %u\n", (unsigned int)4294967296);
		ft_putint((unsigned int)4294967296);
		printf("\n");

		printf("Case #7:\n");
		printf("printf: %u\n", (unsigned int)021);
		ft_putint((unsigned int)021);
		printf("\n");

		printf("Case #8:\n");
		printf("printf: %u\n", (unsigned int)0021);
		ft_putint((unsigned int)000021);
		printf("\n");

		printf("Case #9:\n");
		printf("printf: %u\n", (unsigned int)0x2A1);
		ft_putint((unsigned int)0x2A1);
		printf("\n");

		printf("Case #10:\n");
		printf("printf: %u\n", (unsigned int)0x2a1);
		ft_putint((unsigned int)0x2a1);
		printf("\n");

		printf("Case #11:\n");
		printf("printf: %u\n", (unsigned int)0X2a1);
		ft_putint((unsigned int)0X2a1);
		printf("\n");
	}
}