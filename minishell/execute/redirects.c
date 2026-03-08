/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:04:53 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/06 23:18:54 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	heredoc_infile(t_cmd *cmd)
{
	if (cmd->infile_fd > 0)
	{
		if (dup2(cmd->infile_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 infile");
			close (cmd->infile_fd);
			return (1);
		}
		close(cmd->infile_fd);
	}
	return (0);
}

int	redirection_infile(t_cmd *cmd)
{
	int	fd;
	int	i;

	if (!cmd->infile)
		return (0);
	i = 0;
	while (cmd->infile[i])
	{
		fd = open(cmd->infile[i], O_RDONLY);
		if (fd < 0)
			return (perror("open infile"), 1);
		if (!cmd->infile[i + 1] && dup2(fd, STDIN_FILENO) == -1)
			return (perror("dup2 infile"), close(fd), 1);
		close(fd);
		i++;
	}
	return (0);
}

int	redirection_outfile(t_cmd *cmd)
{
	int	fd;
	int	flags;
	int	i;

	if (!cmd->outfile)
		return (0);
	i = 0;
	while (cmd->outfile[i])
	{
		flags = O_WRONLY | O_CREAT;
		if (cmd->append)
			flags |= O_APPEND;
		else
			flags |= O_TRUNC;
		fd = open(cmd->outfile[i], flags, 0644);
		if (fd < 0)
			return (perror("open outfile"), 1);
		if (!cmd->outfile[i + 1] && dup2(fd, STDOUT_FILENO) == -1)
			return (perror("dup2 outfile"), close(fd), 1);
		close(fd);
		i++;
	}
	return (0);
}

static int	null_outfile(t_cmd *cmd)
{
	int	fd;
	int	i;

	if (cmd->outfile)
	{
		i = 0;
		while (cmd->outfile[i])
		{
			if (cmd->append)
				fd = open(cmd->outfile[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
			else
				fd = open(cmd->outfile[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd < 0)
			{
				perror(cmd->outfile[i]);
				return (1);
			}
			close(fd);
			i++;
		}
	}
	return (0);
}

int	handle_null_redirections(t_cmd *cmd)
{
	int		fd;
	int		i;

	if (cmd->infile)
	{
		i = 0;
		while (cmd->infile[i])
		{
			fd = open(cmd->infile[i], O_RDONLY);
			if (fd < 0)
			{
				perror(cmd->infile[i]);
				return (1);
			}
			close(fd);
			i++;
		}
	}
	if (null_outfile(cmd) == 1)
		return (1);
	return (0);
}
