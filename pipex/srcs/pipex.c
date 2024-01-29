/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:53:49 by ggispert          #+#    #+#             */
/*   Updated: 2024/01/29 19:29:43 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int _open(char *file, char wr)
{
	int fd;

	if (wr)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void _close(int fd)
{
	int close_value;

	close_value = close(fd);
	if (close_value < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
}

void exec_command(char *cmd, int input_fd, int output_fd)
{
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	_close(input_fd);
	_close(output_fd);
	char *cmd_args[] = {"sh", "-c", cmd, NULL};
	execve("/bin/sh", cmd_args, NULL);
	exit(EXIT_FAILURE);
}

char *get_path(char **envp)
{
	int i;
	char *path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
			return (path);
		}
		i++;
	}
	return (NULL);
}

void exec_first_child(char **argv, char **enpv, int pipe_fd[2])
{
	int input_file_fd;

	_close(pipe_fd[0]);
	input_file_fd = _open(argv[1], 0);
	dup2(input_file_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	_close(input_file_fd);
	_close(pipe_fd[1]);
	char *cmd_args[] = {"sh", "-c", argv[2], NULL};
	execve("/bin/sh", cmd_args, NULL);
	exit(EXIT_FAILURE);
}

void exec_second_child(char **argv, int pipe_fd[2])
{
	int output_file_fd;

	_close(pipe_fd[1]);
	if (!access(argv[4], F_OK))
		exit(EXIT_FAILURE);
	output_file_fd = _open(argv[4], 1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output_file_fd, STDOUT_FILENO);
	_close(pipe_fd[0]);
	_close(output_file_fd);
	char *cmd_args[] = {"sh", "-c", argv[3], NULL};
	execve("/bin/sh", cmd_args, NULL);
	exit(EXIT_FAILURE);
}

void pipex(char **argv, char **envp)
{
	(void) envp;
	int pipe_fd[2];
	int status;
	int	first_child;
	int	second_child;
	// access() before open?
	//Check for different file permissions
	// Use WIFEXITSTATUS
	// Maybe open the files in the parent process before the fork?
	pipe(pipe_fd);
	first_child = fork();
	if (first_child < 0)
		perror("fork failed");
	if (first_child == 0)
	{
		exec_first_child(argv, envp, pipe_fd);
	}
	second_child = fork();
	if (second_child < 0)
		perror("fork failed");
	if (second_child == 0)
	{
		exec_second_child(argv, pipe_fd);
	}
	_close(pipe_fd[0]);
	_close(pipe_fd[1]);
	waitpid(first_child, &status, 0);
	waitpid(second_child, &status, 0);
	if (WEXITSTATUS(status) == EXIT_FAILURE)
	{
		ft_printf("Something on the children went wrong\n");
	}
	// if (pid > 0)
	// {
	// 	_close(pipe_fd[1]);
	// 	waitpid(pid, &status, 0);
	// 	if (WIFEXITED(status))
	// 	{
	// 		if (WEXITSTATUS(status) == EXIT_SUCCESS)
	// 		{
	// 			if (!access(argv[3], F_OK))
	// 				ft_printf("Command %s not exists.\n", argv[3]);
	// 			else
	// 			{
	// 				output_file_fd = _open(argv[4], 1);
	// 				exec_command(argv[3], pipe_fd[0], output_file_fd);
	// 			}
	// 		}
	// 		else
	// 		{
	// 		}
	// 	}
	// 	else
	// 	{
	// 	}
	// }
	// else if (pid == 0)
	// {
	// 	input_file_fd = _open(argv[1], 0);
	// 	_close(pipe_fd[0]);
	// 	exec_command(argv[2], input_file_fd, pipe_fd[1]);
	// }
	// else
	// {
	// 	ft_printf("Failure while forking\n");
	// 	exit(EXIT_FAILURE);
	// }
}
