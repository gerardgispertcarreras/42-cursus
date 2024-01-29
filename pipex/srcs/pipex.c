/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:53:49 by ggispert          #+#    #+#             */
/*   Updated: 2024/01/29 14:19:40 by ggispert         ###   ########.fr       */
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

void pipex(char **argv, char **envp)
{
	(void) envp;
	int input_file_fd;
	int output_file_fd;
	int pipe_fd[2];
	int status;
	// access() before open?
	// Use WIFEXITSTATUS
	// Maybe open the files in the parent process before the fork?
	pipe(pipe_fd);
	int pid = fork();
	if (pid > 0)
	{
		_close(pipe_fd[1]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == EXIT_SUCCESS)
			{
				ft_printf("Child process terminated successfully\n");
				if (!access(argv[4], F_OK))
					ft_printf("Command %s not exists.\n", argv[4]);
				else
				{
					output_file_fd = _open(argv[4], 1);
					exec_command(argv[3], pipe_fd[0], output_file_fd);
				}
			}
			else
			{
				ft_printf("Child process terminated with failure\n");
			}
		}
		else
		{
			ft_printf("Child process terminated abnormally\n");
		}
	}
	else if (pid == 0)
	{
		input_file_fd = _open(argv[1], 0);
		_close(pipe_fd[0]);
		exec_command(argv[2], input_file_fd, pipe_fd[1]);
	}
	else
	{
		ft_printf("Failure while forking\n");
		exit(EXIT_FAILURE);
	}
}
