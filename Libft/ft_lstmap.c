/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:12:14 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/17 14:25:21 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	len;
	size_t	i;
	t_list	lst2;
	t_list	lst_b;
	t_list	lst2_b;

	len = ft_lstsize(lst);
	i = 0;
	while (i < len)
	{
		lst2 = ft_lstnew(lst)
	}
}
