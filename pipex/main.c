/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:44:27 by tafonso           #+#    #+#             */
/*   Updated: 2025/10/06 17:27:48 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;

	if (ac != 5)
		leave_program("Usage: ./pipex file1 cmd1 cmd2 file2", 1);
	pipex.infile = open(av[1], O_RDONLY);
	pipex.outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipe(pipex.fd) == -1)
	{
		close_fds(&pipex);
		leave_program("Pipe error", 0);
	}
	if (pipex.infile < 0 || pipex.outfile < 0)
	{
		close_fds(&pipex);
		leave_program("Error opening files", 0);
	}
	pipex.pid1 = fork();
	child_process1(&pipex, av[2], envp);
	pipex.pid2 = fork();
	child_process2(&pipex, av[3], envp);
	close_fds(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
