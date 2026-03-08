/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_unclosed_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:07:01 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/06 22:34:25 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	has_unclosed_quotes(const char *line)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '"') && quote == 0)
			quote = line[i];
		else if (line[i] == quote)
			quote = 0;
		i++;
	}
	return (quote != 0);
}

static void	remove_quotes_array(char **arr)
{
	char	*tmp;
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		tmp = remove_quotes_token(arr[i]);
		free(arr[i]);
		arr[i] = tmp;
		i++;
	}
}

void	remove_quotes_redirs(t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current)
	{
		remove_quotes_array(current->infile);
		remove_quotes_array(current->outfile);
		remove_quotes_array(current->heredoc_delim);
		current = current->next;
	}
}
