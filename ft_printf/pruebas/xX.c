#include <unistd.h>
#include <stdio.h>
#include "../libftprintf.h"


int main()
{
	printf("Case #1:\n");
	printf("printf: %x\n", 180);
	printf("printf: %X\n", 180);
	x_format(180);
	X_format(180);

	printf("Case #2:\n");
	printf("printf: %x\n", -492);
	printf("printf: %X\n", -492);
	x_format(-492);
	X_format(-492);

	printf("Case #3:\n");
	printf("printf: %x\n", 2147483647);
	printf("printf: %X\n", 2147483647);
	x_format(2147483647);
	X_format(2147483647);

	printf("Case #4:\n");
	printf("printf: %x\n", (unsigned int)4294967296);
	printf("printf: %X\n", (unsigned int)4294967296);
	x_format((unsigned int)4294967296);
	X_format((unsigned int)4294967296);

	printf("Case #6:\n");
	printf("printf: %x\n", (unsigned int)4294967295);
	printf("printf: %X\n", (unsigned int)4294967295);
	x_format((unsigned int)4294967295);
	X_format((unsigned int)4294967295);

	printf("Case #7:\n");
	printf("printf: %x\n", 021);
	printf("printf: %X\n", 021);
	x_format(021);
	X_format(021);

	printf("Case #8:\n");
	printf("printf: %x\n", 0021);
	printf("printf: %X\n", 0021);
	x_format(0021);
	X_format(0021);

	printf("Case #9:\n");
	printf("printf: %x\n", 0x2A1);
	printf("printf: %X\n", 0x2A1);
	x_format(0x2A1);
	X_format(0x2A1);

	printf("Case #10:\n");
	printf("printf: %x\n", 0x2a1);
	printf("printf: %X\n", 0x2a1);
	x_format(0x2a1);
	X_format(0x2a1);

	printf("Case #11:\n");
	printf("printf: %x\n", 0X2a1);
	printf("printf: %X\n", 0X2a1);
	x_format(0X2a1);
	X_format(0X2a1);
}