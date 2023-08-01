/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:14:34 by ggispert          #+#    #+#             */
/*   Updated: 2023/08/01 20:58:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	saved[BUFFER_SIZE + 1] = {[0] = '\0'};
	char		*line;
	int			error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_full_line(fd, saved, error);
	return (line);
}

char	*get_full_line(int fd, char *saved, int *error)
{
	char	*line;
	char	finished;
	char	*buffer;
	int		rd;

	//buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer = ft_strdup(saved);
	if (!buffer)
		return (ft_protection(buffer, error));
	finished = save_endl(buffer, saved);
	while (!finished)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (ft_protection(buffer, error));
		buffer[rd] = '\0';
		//evaluar si tenemos el endl y cambiar el finished si es el caso
		line = ft_strjoin(line, buffer);
		if (line == NULL)
			return (ft_protection(buffer, error));
	}
	free(buffer);
	return (line);
}

int	save_endl(char *buffer, char **line, char *saved)
{
	int	i;

	i = search_endl(buffer);
	saved[0] = '\0';
	if (i > 0)
	{
		ft_strlcpy(saved, buffer + i, BUFFER_SIZE + 1);
		buffer[i] = '/0';
	}
	return (i);
}

int	search_endl(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
	}
	return (0);
}

char	*ft_protection(char *s, int *error)
{
	*error = -1;
	free(s);
	return (NULL);
}

