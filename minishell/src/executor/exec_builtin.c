/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:53:58 by tafonso           #+#    #+#             */
/*   Updated: 2025/11/06 11:55:30 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(char **av)
{
	if (!ft_strcmp(av[0], "cd"))
		cd_builtin(av);
	if (!ft_strcmp(av[0], "echo"))
		echo_builtin(av);
	if (!ft_strcmp(av[0], "pwd"))
		pwd_builtin(av);
	if (!ft_strcmp(av[0], "export"))
		export_builtin(av);
	if (!ft_strcmp(av[0], "unset"))
		unset_builtin(av);
	if (!ft_strcmp(av[0], "env"))
		env_builtin(av);
	if (!ft_strcmp(av[0], "exit"))
		exit_builtin(av);
}