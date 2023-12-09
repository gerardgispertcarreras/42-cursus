/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:17:11 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:54:29 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"

typedef struct s_node
{
	int value;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *bot;
	int size;
} t_stack;

// Init, free and error funcs
void init_stack(t_stack *S);
void convert_arg_to_stack(int argc, char **argv, t_stack *A);
void check_is_int(char *s);
void check_not_dup(int *nums, int index);
void simplify_stack(t_stack *A, int *nums, int size);
void free_stack(t_stack *S);
void free_nodes(t_node *n);
void error_handler(void);

// Main algorithm funcs
void push_swap(t_stack *A, t_stack *B);
void algorithm_simple(t_stack *A, t_stack *B);
void	select_sorting(t_stack *a, t_stack *b, char stack_selected, char sort_ascending);
void sort2(t_stack *a, t_stack *b, char stack_selected, char sort_ascending);
void sort3(t_stack *a, t_stack *b, char stack_selected, char sort_ascending);
void sort4(t_stack *a, t_stack *b, char stack_selected, char sort_ascending);
void algorithm_complex(t_stack *A, t_stack *B, int split_parts);
void	split_stack(t_stack *A, t_stack *B, int split);
void	reorder(t_stack *A, t_stack *B);

// Operation handler
void operate(t_stack *A, t_stack *B, char *operation);
void swap(t_stack *A, t_stack *B, char stack);
void push(t_stack *A, t_stack *B, char stack);
void rotate(t_stack *A, t_stack *B, char stack);
void reverse_rotate(t_stack *A, t_stack *B, char stack);

// Stack operations
void swap_stack(t_stack *stack);
void set_stack_top(t_stack *stack, t_node *node);
void remove_stack_top(t_stack *stack);
void set_stack_bot(t_stack *stack, t_node *node);
void remove_stack_bot(t_stack *stack);

// Utils for the algorithms
void split_num(t_stack *A, t_stack *B, int pivot_top, int pivot_bot);
int calc_moves(t_stack *B, int n);
void decide_move_flow(const int moves, int *direction, char **operation, char stack_selected);
void move_to_index(t_stack *A, t_stack *B, char stack_selected, int index);
t_stack *stack_selector(t_stack *a, t_stack *b, char stack_selected);
void reset_stack(t_stack *a, t_stack *b, char stack_selected, char sort_ascending);
char *operation_conversor(char *operation, char stack_selected);
void execute_moves_simple(t_stack *a, t_stack *b, int moves, char stack_selected);
char execute_moves_complex(t_stack *A, t_stack *B, int moves, int n);
char is_sorted(t_stack *stack, char sort_ascending);
char evaluate_sorting(int a, int b, char sort_ascending);
int get_index_minimum_stack(t_stack *stack);
int calc_moves_by_index(t_stack *stack, int index);
int calc_moves_by_num(t_stack *stack, int index);
int get_index_top_stack(t_stack *stack, char sort_ascending);
int search_swap(t_stack *stack, char sort_ascending);
char are_swapable(int a, int b, t_stack *stack, char sort_ascending);
char are_immediate(int a, int b, t_stack *stack, char sort_ascending);
char	are_edges(int a, int b, t_stack *stack, char sort_ascending);
