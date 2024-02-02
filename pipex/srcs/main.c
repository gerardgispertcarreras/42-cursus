/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:53:49 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/02 15:11:49 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	status;
	int	child1;
	int	child2;

	if (argc != 5)
		ft_custom_error(EXIT_FAILURE, PIPEX, INARG, NULL);
	if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, PIPEX, NULL);
	child1 = fork();
	if (child1 == -1)
		ft_error(EXIT_FAILURE, PIPEX, NULL);
	if (child1 == 0)
		first_child(argv[1], pipe_fd, argv[2], envp);
	child2 = fork();
	if (child2 == -1)
		ft_error(EXIT_FAILURE, PIPEX, NULL);
	if (child2 == 0)
		second_child(argv[4], pipe_fd, argv[3], envp);
	_close(pipe_fd[0]);
	_close(pipe_fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	return (WEXITSTATUS(status));
}

void	exec_child(int input_fd, int output_fd, char *command, char **envp)
{
	char	**path;
	char	*cmd;
	char	**cmd_args;

	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	_close(input_fd);
	_close(output_fd);
	cmd_args = ft_split_args(command);
	if (ft_strchr(cmd_args[0], '/') != NULL)
		exec_command_directly(cmd_args, envp);
	path = get_path(envp);
	while (*path)
	{
		cmd = ft_strjoin(*path, cmd_args[0]);
		if (cmd == NULL)
			ft_custom_error(EXIT_FAILURE, PIPEX, MALLOCERR, NULL);
		execve(cmd, cmd_args, envp);
		free(cmd);
		++path;
	}
	ft_custom_error(127, PIPEX, CNF, cmd_args[0]);
}

void	first_child(char *input_file, int pipe_fd[2], char *cmd, char **envp)
{
	int	input_file_fd;

	_close(pipe_fd[0]);
	input_file_fd = _open(input_file, 0);
	exec_child(input_file_fd, pipe_fd[1], cmd, envp);
}

void	second_child(char *output_file, int pipe_fd[2], char *cmd, char **envp)
{
	int	output_file_fd;

	_close(pipe_fd[1]);
	output_file_fd = _open(output_file, 1);
	exec_child(pipe_fd[0], output_file_fd, cmd, envp);
}

char	**get_path(char **envp)
{
	int		i;
	char	*path;
	char	**splitted_path;
	char	path_found;

	i = 0;
	path_found = 0;
	while (envp[i] && !path_found)
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
			path_found = 1;
		}
		i++;
	}
	if (!path_found)
		path = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	if (!path)
		ft_custom_error(EXIT_FAILURE, PIPEX, MALLOCERR, NULL);
	splitted_path = ft_split(path, ':');
	if (!splitted_path)
		ft_custom_error(EXIT_FAILURE, PIPEX, MALLOCERR, NULL);
	add_slash(&splitted_path);
	return (splitted_path);
}
