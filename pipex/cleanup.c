/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:26:49 by tafonso           #+#    #+#             */
/*   Updated: 2025/09/10 16:39:55 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(t_pipe *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
}

void	leave_program(char *message, int flag)
{
	if (!flag)
	{
		perror(message);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("%s\n", message);
		exit(EXIT_FAILURE);
	}
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
