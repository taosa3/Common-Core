/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:19:47 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/06 22:39:22 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_env_list(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		free(env);
		env = tmp;
	}
}

static int	ft_strdigit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit((int)str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	exit_checks(t_data *data, t_cmd *cmd)
{
	write(1, "exit\n", 5);
	if (cmd->args[1] && ft_strdigit(cmd->args[1]) == 0)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		data->should_exit = 1;
		return (data->last_exit_status = 2, 2);
	}
	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd(": too many arguments\n", 2);
		data->last_exit_status = 1;
		return (1);
	}
	return (0);
}

int	exit_builtin(t_data *data, t_cmd *cmd)
{
	long long	status;
	int			ret;

	if (!cmd)
		cmd = data->cmd;
	status = 0;
	ret = exit_checks(data, cmd);
	if (ret != 0)
		return (data->last_exit_status);
	if (cmd->args && cmd->args[1])
	{
		if (ft_is_llong(cmd->args[1]))
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(cmd->args[1], 2);
			return (ft_putstr_fd(": numeric argument required\n",
					2), data->should_exit = 1, data->last_exit_status = 2, 2);
		}
		status = ft_atoll(cmd->args[1]);
		status = status % 256;
	}
	else
		status = data->last_exit_status;
	data->should_exit = 1;
	return (status);
}
