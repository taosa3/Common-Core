/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:04:26 by tafonso           #+#    #+#             */
/*   Updated: 2025/09/10 16:39:13 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(t_pipe *pipex, char *cmd1, char **envp)
{
	if (pipex->pid1 < 0)
		leave_program("Fork error", 0);
	if (pipex->pid1 == 0)
	{
		dup2(pipex->infile, 0);
		dup2(pipex->fd[1], 1);
		close(pipex->fd[0]);
		execute_command(cmd1, envp);
		exit(EXIT_SUCCESS);
	}
}

void	child_process2(t_pipe *pipex, char *cmd2, char **envp)
{
	if (pipex->pid2 < 0)
		leave_program("Fork error", 0);
	if (pipex->pid2 == 0)
	{
		dup2(pipex->fd[0], 0);
		dup2(pipex->outfile, 1);
		close(pipex->fd[1]);
		execute_command(cmd2, envp);
		exit(EXIT_SUCCESS);
	}
}
