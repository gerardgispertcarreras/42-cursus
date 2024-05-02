/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:24:13 by ggispert          #+#    #+#             */
/*   Updated: 2023/08/30 16:45:08 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	format(char c, va_list args, int *error)
{
	size_t	comp_size;

	comp_size = 0;
	if (c == 'c')
		comp_size += ft_putchar(va_arg(args, int), error);
	else if (c == 's')
		comp_size += ft_putstr(va_arg(args, char *), error);
	else if (c == 'p')
		comp_size += ft_pointhandl(va_arg(args, unsigned long long), error);
	else if (c == 'd')
		comp_size += ft_putint(va_arg(args, int), error);
	else if (c == 'i')
		comp_size += ft_putint(va_arg(args, int), error);
	else if (c == 'u')
		comp_size += ft_putuint(va_arg(args, unsigned int), error);
	else if (c == 'x')
		comp_size += ft_putuinthex(va_arg(args, unsigned int), 0, error);
	else if (c == 'X')
		comp_size += ft_putuinthex(va_arg(args, unsigned int), 1, error);
	else if (c == '%')
		comp_size += ft_putchar('%', error);
	return (comp_size);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	size_t	i;
	size_t	size_printed;
	int		error;

	va_start(args, s);
	i = 0;
	size_printed = 0;
	error = 0;
	while (s[i] != '\0' && error != -1)
	{
		if (s[i] != '%')
		{
			error = write(1, &s[i], 1);
			++size_printed;
		}
		else
			size_printed += format(s[++i], args, &error);
		++i;
	}
	va_end(args);
	if (error == -1)
		return (error);
	return (size_printed);
}
