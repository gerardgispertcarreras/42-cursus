/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:24:28 by ggispert          #+#    #+#             */
/*   Updated: 2023/06/21 17:15:30 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_putstr(char *s, int *error)
{
	size_t	len;
	int	printed;

	len = ft_strlen(s);
	printed = write(1, s, (len * sizeof(char)));
	if (printed == -1)
		*error = -1;
	return (printed);
}
