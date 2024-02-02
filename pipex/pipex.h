/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:54:08 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/02 15:07:22 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# define PIPEX "pipex: "
# define CNF "command not found"
# define INARG "Invalid number of arguments"
# define MALLOCERR "Invalid number of arguments"

int		main(int argc, char **argv, char **envp);

// Execute commands functions
void	exec_child(int input_fd, int output_fd, char *command, char **envp);
void	first_child(char *input_file, int pipe_fd[2], char *cmd, char **envp);
void	second_child(char *output_file, int pipe_fd[2], char *cmd, char **envp);
char	**get_path(char **envp);
void	exec_command_directly(char **cmd_args, char **envp);
void	add_slash(char ***path);

// Error handling functions
int		_open(char *file, char wr);
void	_close(int fd);
void	ft_error(int exit_code, char *source, char *info);
void	ft_custom_error(int exit_code, char *source, char *reason, char *info);

// Split args
char	**ft_split_args(char const *s);
size_t	get_single_quote_length(char const *s);
size_t	get_double_quote_length(char const *s);
size_t	get_word_count_args(char const *s);
size_t	get_word_length_args(char const *s);
size_t	copy_word(char **p, char const *s);
void	trim_excess_arg(char *p);

#endif