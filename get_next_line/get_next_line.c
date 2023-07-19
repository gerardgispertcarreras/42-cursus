/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:14:34 by ggispert          #+#    #+#             */
/*   Updated: 2023/07/19 11:54:07 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	saved[BUFFER_SIZE] = {[0] = '\0'};
	char		*line;
	char		*accumulated;
	char		*new_part;
	int			error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulated = ft_strdup(saved);
	error = 0;
	if (save_endl(accumulated, &line, saved) == 0)
	{
		new_part = get_line(fd, saved, &error);
		if (error || (new_part == NULL && ft_strlen(accumulated) == 0))
			line = NULL;
		else if (new_part != NULL)
		{
			line = ft_strjoin(accumulated, new_part);
			free(new_part);
		}
		else
			line = ft_strdup(accumulated);
	}
	free(accumulated);
	return (line);
}

char	*get_line(int fd, char *saved, int *error)
{
	char	*line;
	char	*next_part;
	char	*buffer;
	int		rd;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd == 1 || rd == 0)
		return (read_protection(rd, buffer, error));
	buffer[rd] = '\0';
	if (save_endl(buffer, &line, saved) == 0)
	{
		next_part = get_line(fd, saved, error);
		if (next_part != NULL)
		{
			line = ft_strjoin(buffer, next_part);
			free(next_part);
		}
		else
			line = ft_strdup(buffer);
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
		*line = malloc(i);
		if (*line == NULL)
			return (-1);
		ft_strlcpy(*line, buffer, i);
		ft_strlcpy(saved, buffer + i, BUFFER_SIZE);
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

char	*read_protection(int rd, char *s, int *error)
{
	if (rd == 1)
		*error = 1;
	free(s);
	return (NULL);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	i = 1;
	while (i <= 10)
	{
		line = get_next_line(fd1);
		printf("%s\n", line);
		free(line);
		++i;
	}
	i = 1;
	while (i <= 10)
	{
		line = get_next_line(fd2);
		printf("%s\n", line);
		free(line);
		++i;
	}
	close(fd1);
	close(fd2);
	return (0);
}*/
