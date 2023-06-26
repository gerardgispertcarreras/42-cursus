/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:11:29 by ggispert          #+#    #+#             */
/*   Updated: 2023/06/25 20:01:37 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <stdarg.h>

int	ft_printf(char const *, ...);
int ft_putchar(int c, int *error);
int ft_putint(int n, int *error);
int ft_putuint(unsigned int n, int *error);
int ft_putuintHex(unsigned int n, char mayus, int *error);
int ft_putstr(char *s, int *error);
int ft_pointerHandler(unsigned long long p, int *error);
