/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:42:33 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/06 23:07:30 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parent_fds(t_cmd *cmd, int *prev_fd, int *fd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (cmd->next)
	{
		close(fd[1]);
		*prev_fd = fd[0];
	}
	else
		*prev_fd = -1;
}

void	wait_children(int children, t_data *data)
{
	int	status;
	int	sig_printed;

	sig_printed = 0;
	while (children-- > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		waitpid(-1, &status, 0);
		signal(SIGINT, ctrlc_handler);
		signal(SIGQUIT, SIG_IGN);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT && !sig_printed)
		{
			ft_putendl_fd("Quit (core dumped)", 2);
			sig_printed = 1;
		}
		if (WIFEXITED(status))
			data->last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			data->last_exit_status = 128 + WTERMSIG(status);
	}
}

int	pipe_error(int prev_fd)
{
	if (prev_fd != -1)
		close(prev_fd);
	perror("pipe");
	return (-1);
}

int	fork_error(int prev_fd, int *fd, int has_pipe)
{
	if (prev_fd != -1)
		close(prev_fd);
	if (has_pipe)
	{
		close(fd[0]);
		close(fd[1]);
	}
	perror("fork");
	return (-1);
}

void	check_builtin_in_pipe(t_cmd *cmd, t_data *data, char **envp, int status)
{
	if (is_builtin(cmd->args[0]))
	{
		status = execute_builtin(data, cmd);
		free_envp(envp);
		free_all(data);
		exit(status);
	}
}
