/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:23:44 by tafonso           #+#    #+#             */
/*   Updated: 2025/09/10 16:40:52 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "printf/ft_printf.h"
# include "printf/libft/libft.h"

typedef struct s_pipe
{
	int		infile;
	int		outfile;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
}				t_pipe;

//pipex_utils.c
char	*ft_strjoin3(char *str1, char *separator, char *str2);
void	execute_command(char *cmd, char **envp);

//cleanup.c
void	close_fds(t_pipe *pipex);
void	leave_program(char *message, int flag);
void	free_split(char **arr);

//processes.c
void	child_process1(t_pipe *pipex, char *cmd1, char **envp);
void	child_process2(t_pipe *pipex, char *cmd2, char **envp);
#endif
