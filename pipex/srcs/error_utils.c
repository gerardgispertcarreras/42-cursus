/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:53:59 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/02 15:06:25 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	_open(char *file, char wr)
{
	int	fd;

	if (wr)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (access(file, W_OK))
			ft_error(2, PIPEX, file);
	}
	else
		fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(EXIT_FAILURE, PIPEX, file);
	return (fd);
}

void	_close(int fd)
{
	int		close_value;
	char	*fd_string;

	close_value = close(fd);
	if (close_value == -1)
	{
		fd_string = ft_itoa(fd);
		if (fd_string == NULL)
			ft_custom_error(EXIT_FAILURE, PIPEX, MALLOCERR, NULL);
		ft_error(EXIT_FAILURE, PIPEX, fd_string);
	}
}

void	ft_error(int exit_code, char *source, char *info)
{
	ft_putstr_fd(source, 2);
	perror(info);
	exit(exit_code);
}

void	ft_custom_error(int exit_code, char *source, char *reason, char *info)
{
	ft_putstr_fd(source, 2);
	if (info)
		ft_putstr_fd(ft_strjoin(info, ": "), 2);
	ft_putendl_fd(reason, 2);
	exit(exit_code);
}
