/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:45:32 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/05 20:20:41 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function to print values of nodes in the stack
void printStackValues(t_stack* stack) {
	if (stack == NULL || stack->top == NULL) {
			ft_printf("Stack is empty\n");
			return;
	}

	t_node* current = stack->top;

	ft_printf("Stack values:\n");
	while (current != NULL) {
			ft_printf("%d\n", current->value); // Access 'value' instead of 'data'
			current = current->next;
	}
}
