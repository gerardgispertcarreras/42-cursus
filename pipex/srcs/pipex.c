/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:53:49 by ggispert          #+#    #+#             */
/*   Updated: 2024/01/23 10:40:49 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void pipex(char **argv)
{
	int input_file_fd;
	int output_file_fd;
	int close_value;
	// access() before open?
	input_file_fd = open(argv[1], O_RDONLY);
	if (input_file_fd < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	output_file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_file_fd < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	dup2(input_file_fd, STDIN_FILENO);
	dup2(output_file_fd, STDOUT_FILENO);
	int pid = 1;
	for (int i = 2; i < 4 && pid != 0; ++i)
	{
		pid = fork();
		if (pid == 0)
		{
			write(2, "Child process\n", 14);
			char *args[] = {"sh", "-c", argv[i], NULL};
			char *envp[] = {NULL};
			execve("/bin/sh", args, envp);
		}
	}
	if (pid != 0)
	{
		waitpid(pid, NULL, 0);
		close_value = close(output_file_fd);
		if (close_value == -1)
		{
			ft_printf("Failure while closing\n");
			exit(EXIT_FAILURE);
		}
	}
}
