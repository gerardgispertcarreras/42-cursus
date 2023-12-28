/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_conversor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:39:50 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 16:57:54 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function returns the operation joined with the stack selected.
	Params:
		operation: string of the operation.
		selected: selected stack.
*/
char	*operation_conversor(char *operation, char selected)
{
	char	*op_converted;
	int		size;

	op_converted = malloc((ft_strlen(operation) + 2) * sizeof(char));
	size = ft_strlen(operation);
	ft_strlcpy(op_converted, operation, 3);
	op_converted[size] = selected;
	op_converted[size + 1] = '\0';
	return (op_converted);
}
