/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:01:00 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/26 18:12:49 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst != NULL)
		{
			while ((*lst)->next != NULL)
			{
				lst = &(*lst)->next;
			}
			(*lst)->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}
