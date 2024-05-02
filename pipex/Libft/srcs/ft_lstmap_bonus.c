/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:12:14 by ggispert          #+#    #+#             */
/*   Updated: 2023/04/29 12:34:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	void	*cont;

	if (lst != NULL)
	{
		cont = (*f)(lst->content);
		if (cont == NULL)
			return (NULL);
		l = ft_lstnew(cont);
		if (l == NULL)
		{
			free(cont);
			return (NULL);
		}
		l->next = ft_lstmap(lst->next, f, del);
		if (l->next == NULL && lst->next != NULL)
		{
			ft_lstdelone(l, del);
			l = NULL;
		}
		return (l);
	}
	return (NULL);
}
