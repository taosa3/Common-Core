/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:19:06 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/06 01:07:37 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pwd_builtin(t_data *data)
{
	char	*pwd;
	int		flag;

	flag = 0;
	pwd = data->pwd;
	if (!pwd)
	{
		flag = 1;
		pwd = getcwd(NULL, 0);
	}
	if (pwd)
		printf("%s\n", pwd);
	else
		ft_putstr_fd("pwd: error retrieving current directory: "
			"getcwd: cannot access parent directories: "
			"No such file or directory\n", 2);
	if (flag)
		free(pwd);
	return (0);
}
