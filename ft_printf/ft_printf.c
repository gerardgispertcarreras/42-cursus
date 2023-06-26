/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:24:13 by ggispert          #+#    #+#             */
/*   Updated: 2023/06/26 14:05:32 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	format(char c, va_list args, int *error)
{
	size_t	sizeOfParse;

	sizeOfParse = 0;
	if (c == 'c')
		sizeOfParse += ft_putchar(va_arg(args, int), error);
	else if (c == 's')
		sizeOfParse += ft_putstr(va_arg(args, char *), error);
	else if (c == 'p')
		sizeOfParse += ft_pointerHandler(va_arg(args, unsigned long long), error);
	else if (c == 'd')
		sizeOfParse += ft_putint(va_arg(args, int), error);
	else if (c == 'i')
		sizeOfParse += ft_putint(va_arg(args, int), error);
	else if (c == 'u')
		sizeOfParse += ft_putuint(va_arg(args, unsigned int), error);
	else if (c == 'x')
		sizeOfParse += ft_putuintHex(va_arg(args, unsigned int), 0, error);
	else if (c == 'X')
		sizeOfParse += ft_putuintHex(va_arg(args, unsigned int), 1, error);
	else if (c == '%')
		sizeOfParse += ft_putchar('%', error);
	return (sizeOfParse);
}

int ft_printf(char const *s, ...)
{
	va_list args;
	size_t	i;
	size_t sizePrinted;
	int	error;

	va_start(args, s);
	i = 0;
	sizePrinted = 0;
	error = 0;
	while (s[i] != '\0' && error != -1)
	{
		if (s[i] != '%')
		{
			error = write(1, &s[i], 1);
			++sizePrinted;
		}
		else
			sizePrinted += format(s[++i], args, &error);
		++i;
	}
	va_end(args);
	return (sizePrinted);
}