/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:53:59 by ggispert          #+#    #+#             */
/*   Updated: 2024/01/29 14:09:14 by ggispert         ###   ########.fr       */
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
	(void) argv;
	if (argc != 5)
		ft_usage();
	pipex(argv, envp);
	return (EXIT_SUCCESS);
}