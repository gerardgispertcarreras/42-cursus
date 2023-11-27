/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:17:11 by ggispert          #+#    #+#             */
/*   Updated: 2023/10/21 19:22:54 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"

typedef struct s_stack
{
	int	*values;
	int	size;
}				t_stack;

void	push_swap(t_stack *A, t_stack *B);
void	convert_arg_to_stack(int argc, char **argv, t_stack *A);
void	operate(t_stack *A, t_stack *B, char *op);
