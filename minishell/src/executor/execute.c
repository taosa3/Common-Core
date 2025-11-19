/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:07:24 by tafonso           #+#    #+#             */
/*   Updated: 2025/11/18 15:27:50 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirects(t_cmd *cmd)
{
	int infile_fd;
	int outfile_fd;

	outfile_fd = 0;
	infile_fd = 0;
	if (cmd->infile)
		{
			infile_fd = open(cmd->infile, O_RDONLY);
			if (infile_fd < 0)
				//function to display error and free and close everything
			dup2(infile_fd, STDIN_FILENO);
			close(infile_fd);
		}
	if (cmd->outfile)
	{
		if (cmd->append)
			outfile_fd = open(cmd->outfile, O_CREAT, O_WRONLY, O_APPEND, 0644);
		else
			outfile_fd = open(cmd->outfile, O_CREAT, O_WRONLY, O_TRUNC, 0644);
		if (outfile_fd < 0)
			//function to display error and free and close everything
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
	}
}

void	handle_heredoc(char *delimiter)
{
	int	fd[2];
	char *line;

	if (pipe(fd) == -1)
		//error
	while (1)
	{
		line = readline(">");
		if (!line || ft_strcmp(line, delimiter))
			break ;
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
		//use readline and if the line is the same has the delimiter then return write 
	}
	close(fd[1]);
	return (fd[0]);
}

void	execute(t_cmd *cmd, char **env)
{
	int fd[2];
	
	while (!cmd && !cmd->next)
	{
		redirects(cmd);
		if (cmd->heredoc)
			handle_heredoc(cmd->heredoc_delimiter);
		if (cmd->pipe_to_next == 0)
		{
			if (is_builtin(cmd->av[0]))
				exec_builtin(cmd->av);
			execve(find_command_path(cmd->av[0], env), cmd->av, env);
		}
		if (cmd->pipe_to_next == 1)
		{
			if (pipe(fd) == -1)
				//function to leave and free everything
			
		}
		cmd = cmd->next;
	}
}