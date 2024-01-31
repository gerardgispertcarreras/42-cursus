/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:53:49 by ggispert          #+#    #+#             */
/*   Updated: 2024/01/30 16:11:58 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_usage()
{
	ft_printf("ERROR: Bad Usage\nYou should call the function with 2 commands and 2 files.\n\
For example: ./pipex <input_file> <command1> <command2> <ouput_file>\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int input_file_fd;
	int output_file_fd;

	input_file_fd = _open(argv[1], 0);
	output_file_fd = _open(argv[4], 1);
	if (argc != 5)
		ft_usage();
	argv[argc - 1] = NULL;
	pipex(input_file_fd, output_file_fd, &argv[2], envp);
	_close(input_file_fd);
	_close(output_file_fd);
	return (EXIT_SUCCESS);
}

void pipex(int input_fd, int output_fd, char **commands, char **envp)
{
	int	pipe_fd[2];
	int	status;
	int	first_child;
	int	second_child;
	// access() before open?
	//Check for different file permissions
	pipe(pipe_fd);
	first_child = fork();
	if (first_child < 0)
		exit(EXIT_FAILURE);
	if (first_child == 0)
	{
		_close(pipe_fd[0]);
		_close(output_fd);
		exec_child(input_fd, pipe_fd[1], commands[0], envp);
	}
	second_child = fork();
	if (second_child < 0)
		exit(EXIT_FAILURE);
	if (second_child == 0)
	{
		_close(pipe_fd[1]);
		_close(input_fd);
		exec_child(pipe_fd[0], output_fd, commands[1], envp);
	}
	_close(pipe_fd[0]);
	_close(pipe_fd[1]);
	waitpid(first_child, &status, 0);
	waitpid(second_child, &status, 0);
}

void exec_child(int input_fd, int output_fd, char *command, char **envp)
{
	char	**path;
	char	*cmd;
	char	**cmd_args;

	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	_close(input_fd);
	_close(output_fd);
	path = ft_split(get_path(envp), ':');
	add_slash(&path);
	cmd_args = ft_split(command, ' ');
	while (*path)
	{
		cmd = ft_strjoin(*path, cmd_args[0]);
		execve(cmd, cmd_args, envp);
		free(cmd);
		++path;
	}
	cmd = cmd_args[0];
	cmd_args[0] = ft_strrchr(cmd_args[0], '/') + 1;
	execve(cmd, cmd_args, envp);
	exit(EXIT_FAILURE);
}

void exec_first_child(char **argv, char **envp, int pipe_fd[2])
{
	int		input_file_fd;
	char	**path;
	char	*cmd;
	char	**cmd_args;

	_close(pipe_fd[0]);
	input_file_fd = _open(argv[1], 0);
	dup2(input_file_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	_close(input_file_fd);
	_close(pipe_fd[1]);
	path = ft_split(get_path(envp), ':');
	add_slash(&path);
	cmd_args = ft_split(argv[2], ' ');
	while (*path)
	{
		cmd = ft_strjoin(*path, cmd_args[0]);
		execve(cmd, cmd_args, envp);
		free(cmd);
		++path;
	}
	cmd = cmd_args[0];
	cmd_args[0] = ft_strrchr(cmd_args[0], '/') + 1;
	write(2, cmd_args[0], ft_strlen(cmd_args[0]));
	// Free memory
	execve(cmd, cmd_args, envp);
	// free(cmd);
	// free(cmd_args);
	// free(path);
	exit(EXIT_FAILURE);
}

void exec_second_child(char **argv, char **envp, int pipe_fd[2])
{
	int		output_file_fd;
	char	**path;
	char	*cmd;
	char	**cmd_args;

	_close(pipe_fd[1]);
	output_file_fd = _open(argv[4], 1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output_file_fd, STDOUT_FILENO);
	_close(pipe_fd[0]);
	_close(output_file_fd);
	path = ft_split(get_path(envp), ':');
	add_slash(&path);
	cmd_args = ft_split(argv[3], ' ');
	while (*path)
	{
		cmd = ft_strjoin(*path, cmd_args[0]);
		execve(cmd, cmd_args, envp);
		free(cmd);
		++path;
	}
	cmd = cmd_args[0];
	cmd_args[0] = ft_strrchr(cmd_args[0], '/');
	write(2, cmd_args[0], ft_strlen(cmd_args[0]));
	execve(cmd, cmd_args, envp);
	exit(EXIT_FAILURE);
}
