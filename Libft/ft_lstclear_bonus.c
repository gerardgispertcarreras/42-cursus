/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:16:22 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/26 18:27:11 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst)
	{
		if (*lst != NULL)
		{
			ft_lstclear(&(*lst)->next, del);
			ft_lstdelone(*lst, del);
			*lst = NULL;
		}
	}
}
