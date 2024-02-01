/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:53:49 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/01 12:58:42 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		ft_custom_error(EXIT_FAILURE, PIPEX, INARG, NULL); //CHECK ERROR
	return(pipex(argv, envp));
}

int	pipex(char **argv, char **envp)
{
	int	pipe_fd[2];
	int	status;
	int	first_child;
	int	second_child;
	// access() before open?
	//Check for different file permissions
	if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, PIPEX, NULL);
	first_child = fork();
	if (first_child == -1)
		ft_error(EXIT_FAILURE, PIPEX, NULL);
	if (first_child == 0)
		exec_first_child(argv[1], pipe_fd, argv[2], envp);
	second_child = fork();
	if (second_child == -1)
		ft_error(EXIT_FAILURE, PIPEX, NULL);
	if (second_child == 0)
		exec_second_child(argv[4], pipe_fd, argv[3], envp);
	_close(pipe_fd[0]);
	_close(pipe_fd[1]);
	waitpid(first_child, &status, 0);
	waitpid(second_child, &status, 0);
	return (WEXITSTATUS(status));
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
	path = ft_split(get_path(envp), ':'); //CHECK ERROR
	add_slash(&path);
	cmd_args = ft_split_args(command, ' '); //CHECK ERROR
	if (ft_strchr(cmd_args[0], '/') != NULL)
	{
		cmd = cmd_args[0];
		cmd_args[0] = ft_strrchr(cmd_args[0], '/') + 1;
		execve(cmd, cmd_args, envp);
		if (access(cmd, X_OK))
			ft_error(126, PIPEX, cmd);
		ft_error(EXIT_FAILURE, PIPEX, cmd);
	}
	while (*path)
	{
		cmd = ft_strjoin(*path, cmd_args[0]); //CHECK ERROR
		execve(cmd, cmd_args, envp);
		free(cmd);
		++path;
	}
	ft_custom_error(127, PIPEX, CNF, cmd_args[0]);
}

void exec_first_child(char *input_file, int pipe_fd[2], char *command, char **envp)
{
	int		input_file_fd;

	_close(pipe_fd[0]);
	input_file_fd = _open(input_file, 0);
	exec_child(input_file_fd, pipe_fd[1], command, envp);
}

void exec_second_child(char *output_file, int pipe_fd[2], char *command, char **envp)
{
	int		output_file_fd;

	_close(pipe_fd[1]);
	output_file_fd = _open(output_file, 1);
	exec_child(pipe_fd[0], output_file_fd, command, envp);
}
