/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:01:00 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/16 18:15:44 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst != NULL)
	{
		while ((*lst)->next != NULL)
		{
			lst = &lst->next;
		}
		(*lst)->next = new;
	}
	else
	{
		*lst = new;
	}
}