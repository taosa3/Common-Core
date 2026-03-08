/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:46:23 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/05 17:57:39 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_cycle(t_data *data)
{
	if (!data)
		return ;
	free(data->input);
	data->input = NULL;
	free(data->var_name);
	data->var_name = NULL;
	if (data->tokens)
	{
		free_split(data->tokens);
		data->tokens = NULL;
	}
	if (data->cmd)
	{
		free_cmds(data->cmd);
		data->cmd = NULL;
	}
}
