/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:48:41 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/02 14:55:48 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_command_directly(char **cmd_args, char **envp)
{
	char	*cmd;

	cmd = cmd_args[0];
	cmd_args[0] = ft_strrchr(cmd_args[0], '/') + 1;
	execve(cmd, cmd_args, envp);
	if (access(cmd, X_OK))
		ft_error(126, PIPEX, cmd);
	ft_error(EXIT_FAILURE, PIPEX, cmd);
}

void	add_slash(char ***path)
{
	int		i;

	i = 0;
	while ((*path)[i])
	{
		(*path)[i] = ft_strjoin((*path)[i], "/");
		if (!(*path)[i])
			ft_custom_error(EXIT_FAILURE, PIPEX, MALLOCERR, NULL);
		i++;
	}
}
