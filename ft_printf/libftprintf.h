/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:11:29 by ggispert          #+#    #+#             */
/*   Updated: 2023/07/15 20:44:31 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./Libft/libft.h"
# include <stdarg.h>

int	ft_printf(char const *s, ...);
int	ft_putchar(int c, int *error);
int	ft_putint(int n, int *error);
int	ft_putuint(unsigned int n, int *error);
int	ft_putuinthex(unsigned int n, char mayus, int *error);
int	ft_putstr(char *s, int *error);
int	ft_pointhandl(unsigned long long p, int *error);

#endif
