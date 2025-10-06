/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:26:49 by tafonso           #+#    #+#             */
/*   Updated: 2025/10/06 17:08:17 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(t_pipe *pipex)
{
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	if (pipex->fd[0])
		close(pipex->fd[0]);
	if (pipex->fd[1])
		close(pipex->fd[1]);
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
