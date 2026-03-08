/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:46:30 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/06 00:44:50 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_cycle(data);
	if (data->env_list)
	{
		free_env_list(data->env_list);
		data->env_list = NULL;
	}
	if (data->pwd)
		free(data->pwd);
	rl_clear_history();
}
