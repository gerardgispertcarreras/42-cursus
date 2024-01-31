/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:53:59 by ggispert          #+#    #+#             */
/*   Updated: 2024/01/30 17:27:05 by ggispert         ###   ########.fr       */
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

	if (fd == -1)
	{
		ft_error(PIPEX, file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void _close(int fd)
{
	int close_value;

	close_value = close(fd);
	if (close_value == -1)
	{
		ft_error(PIPEX, ft_itoa(fd));
		exit(EXIT_FAILURE);
	}
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

void add_slash(char ***path)
{
	int i;

	i = 0;
	while ((*path)[i])
	{
		char *tmp = ft_strjoin((*path)[i], "/");
		free((*path)[i]);
		(*path)[i] = tmp;
		i++;
	}
}

void	ft_error(char *source, char *additional_info)
{
	ft_putstr_fd(source, 2);
	perror(additional_info);
	exit(EXIT_FAILURE);
}
