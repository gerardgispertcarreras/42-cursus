#include <unistd.h>
#include <stdio.h>
#include "../libftprintf.h"

int main()
{
	int a[80];
	ft_printf("%d\n", ft_printf("Hola, em dic %s. Felicitats %c!\nTinc %u a%cys. El punter es: %p. D[Positiu: %d, Negatiu: %d]. I[Positiu: %i, Negatiu: %i]. x: %x, X: %X. %%", "Gerard", 'g', 20, 'n', a, 23587, -297589, 23587, -297589, 80, 27582937));
	printf("%d\n", printf("Hola, em dic %s. Felicitats %c!\nTinc %u a%cys. El punter es: %p. D[Positiu: %d, Negatiu: %d]. I[Positiu: %i, Negatiu: %i]. x: %x, X: %X. %%", "Gerard", 'g', 20, 'n', a, 23587, -297589, 23587, -297589, 80, 27582937));
}