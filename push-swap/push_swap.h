/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:17:11 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/05 11:39:40 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"

typedef struct s_stack
{
	int	*values;
	int	size;
}				t_stack;

void	init_stack(t_stack *S, int max_size);
void	free_stack(t_stack *S);
void	push_swap(t_stack *A, t_stack *B);
void	algorithm_size3(t_stack *A, t_stack *B);
void	algorithm_size5(t_stack *A, t_stack *B);
void	algorithm_size100(t_stack *A, t_stack *B);
void	algorithm_size500(t_stack *A, t_stack *B);
void	convert_arg_to_stack(int argc, char **argv, t_stack *A);
void	ft_error(void);
void	check_is_int(char *s);
void	check_not_dup(int *nums, int index);
void	simplify_stack(t_stack *A, int *nums, int size);
void	split_num(t_stack *A, t_stack *B, int pivot_top, int pivot_bot);
void	split_stack(t_stack *A, t_stack *B, int split);
int		calc_moves(t_stack *B, int n);
void	decide_move_flow(const int moves, char *direction, char **op);
char	prepare_push(t_stack *A, t_stack *B, int moves, int n);
void	reorder(t_stack *A, t_stack *B);
void	operate(t_stack *A, t_stack *B, char *op);
int		top(t_stack *S);
int		size(t_stack *S);
char	is_sorted(t_stack *S);
