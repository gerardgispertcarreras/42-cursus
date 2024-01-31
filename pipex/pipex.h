/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:54:08 by ggispert          #+#    #+#             */
/*   Updated: 2024/01/30 16:36:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./Libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>

# define BASH "bash: "
# define PIPEX "pipex: "
# define COPEN ": can not open the file: "
# define CNF ": command not found"
# define CCLOSE ": Fd can not be closed"
# define PERM ": Permission denied"
# define BFD ": Bad file descriptor"
# define EFORK ": error creating fork"
# define NFILEDIR "no such file or directory: "
# define INARG ": Invalid number of arguments"
# define MALLOCER ": error trying to allocate memory"
# define NEXECVE ": error on execve"

// Function prototypes
void	pipex(int input_fd, int output_fd, char **commands, char **envp);
void	exec_child(int input_fd, int output_fd, char *command, char **envp);
void	exec_first_child(char **argv, char **envp, int pipe_fd[2]);
void	exec_second_child(char **argv, char **envp, int pipe_fd[2]);
void	ft_usage(void);
int		_open(char *file, char wr);
void	_close(int fd);
char	*get_path(char **envp);
void	add_slash(char ***path);
void	ft_error(char *source, char *additional_info);

#endif