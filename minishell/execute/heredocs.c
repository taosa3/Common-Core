/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:55:43 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/05 17:05:32 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	run_heredoc(const char *delimiter, t_data *data)
{
	int		fd;
	char	*filename;
	pid_t	pid;
	int		status;
	void	(*prev_sigint)(int);

	fd = create_heredoc_file(&filename);
	if (fd < 0)
		return (-1);
	prev_sigint = signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		return (signal(SIGINT, prev_sigint), close(fd),
			free(filename), perror("fork"), -1);
	if (pid == 0)
		heredoc_child(delimiter, fd, data, filename);
	close(fd);
	waitpid(pid, &status, 0);
	signal(SIGINT, prev_sigint);
	if (WIFSIGNALED(status)
		|| (WIFEXITED(status) && WEXITSTATUS(status) == 130))
		return (unlink(filename), free(filename), -1);
	fd = open(filename, O_RDONLY);
	return (unlink(filename), free(filename), fd);
}

static int	process_cmd_heredocs(t_cmd *cmd, t_data *data)
{
	int	fd;
	int	tmp;
	int	i;

	fd = -1;
	if (!cmd->heredoc || !cmd->heredoc_delim)
		return (0);
	i = 0;
	while (cmd->heredoc_delim[i])
	{
		tmp = run_heredoc(cmd->heredoc_delim[i], data);
		if (tmp == -1)
		{
			if (fd != -1)
				close(fd);
			cmd->infile_fd = -1;
			return (data->last_exit_status = 130, -1);
		}
		if (fd != -1)
			close(fd);
		fd = tmp;
		i++;
	}
	cmd->infile_fd = fd;
	return (0);
}

int	process_heredocs(t_cmd *cmds, t_data *data)
{
	while (cmds)
	{
		if (process_cmd_heredocs(cmds, data) == -1)
			return (-1);
		cmds = cmds->next;
	}
	return (0);
}
