/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:23:58 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/06 22:41:32 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	create_heredoc_file(char **filename)
{
	static int	i;
	char		*num;
	int			fd;

	num = ft_itoa(i++);
	*filename = ft_strjoin("/tmp/.heredoc_", num);
	free(num);
	if (!*filename)
		return (-1);
	fd = open(*filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd < 0)
	{
		free(*filename);
		return (-1);
	}
	return (fd);
}

static void	read_heredoc_input(const char *delimiter, int fd, t_data *data)
{
	char	*line;

	while (1)
	{
		if (g_exit_signal)
			break ;
		line = readline("> ");
		if (!line || g_exit_signal)
		{
			if (!line && !g_exit_signal)
				ft_putendl_fd("warning: heredoc delimited by end-of-file", 2);
			break ;
		}
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write_heredoc(line, fd, data);
	}
}

void	heredoc_child(const char *delimiter, int fd,
	t_data *data, char *filename)
{
	signal(SIGINT, sig_heredoc);
	read_heredoc_input(delimiter, fd, data);
	close(fd);
	free(filename);
	if (g_exit_signal)
	{
		free_all(data);
		exit(130);
	}
	free_all(data);
	exit(0);
}
