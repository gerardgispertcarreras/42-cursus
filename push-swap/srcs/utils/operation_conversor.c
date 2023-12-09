/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_conversor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:39:50 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:54:50 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char *operation_conversor(char *operation, char stack_selected)
{
	char *op_converted;
	int		size;

	op_converted = malloc((ft_strlen(operation) + 2) * sizeof(char));
	size = ft_strlen(operation);
	ft_strlcpy(op_converted, operation, 3);
	op_converted[size] = stack_selected;
	op_converted[size + 1] = '\0';
	return (op_converted);
}