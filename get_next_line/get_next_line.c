/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:14:34 by ggispert          #+#    #+#             */
/*   Updated: 2023/08/08 19:20:11 by ggispert         ###   ########.fr       */
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
	line = get_full_line(fd, saved, &error);
	if (error == -1)
		return (NULL);
	return (line);
}

char	*get_full_line(int fd, char *saved, int *error)
{
	char	*line;
	int		endl;
	char	*buffer;
	int		rd;

	line = NULL;
	rd = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_protection(buffer, line, error));
	ft_strlcpy(buffer, saved, BUFFER_SIZE + 1);
	saved[0] = '\0';
	line = ft_strjoin(line, get_and_save_line(buffer, saved, &endl));
	while (rd != 0 && endl == 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (ft_protection(buffer, line, error));
		buffer[rd] = '\0';
		line = ft_strjoin(line, get_and_save_line(buffer, saved, &endl));
		if (line == NULL && rd != 0)
			return (ft_protection(buffer, line, error));
	}
	free(buffer);
	return (line);
}

char	*get_and_save_line(char *buffer, char *saved, int *endl)
{
	*endl = search_endl(buffer);
	if (*endl > 0)
	{
		ft_strlcpy(saved, buffer + *endl, BUFFER_SIZE + 1);
		buffer[*endl] = '\0';
	}
	return (buffer);
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

char	*ft_protection(char *s1, char *s2, int *error)
{
	*error = -1;
	free(s1);
	free(s2);
	return (NULL);
}
