/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:24:28 by ggispert          #+#    #+#             */
/*   Updated: 2023/08/30 16:45:08 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(int c, int *error)
{
	int	printed;

	printed = write(1, &c, 1);
	if (printed == -1)
		*error = -1;
	return (printed);
}
