/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:53:53 by tafonso           #+#    #+#             */
/*   Updated: 2025/11/06 11:53:54 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_builtin(char **av)
{
	char *home;
	
	if (!av[1])
	{
		home = getenv("HOME");
		if (!home)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (1);
		}
		if (chdir(home) != 0)
		{
			perror("cd");
			return (1);
		}
		return (0);
	}
	if (chdir(av[1]) != 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}
