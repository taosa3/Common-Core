/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:54:12 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/06 22:35:47 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_even_quotes(char *str)
{
	int	i;
	int	single_q;
	int	double_q;

	i = 0;
	single_q = 0;
	double_q = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			single_q++;
		else if (str[i] == '"')
			double_q++;
		i++;
	}
	if (single_q % 2 == 0 && double_q % 2 == 0)
		return (1);
	return (0);
}

void	check_heredoc_quotes(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	data->heredoc_quoted = 0;
	while (data->tokens && data->tokens[i])
	{
		if (ft_strcmp(data->tokens[i], "<<") == 0)
		{
			if (ft_strchr(data->tokens[i + 1], '\'')
				|| ft_strchr(data->tokens[i + 1], '"'))
			{
				if (check_even_quotes(data->tokens[i + 1]))
					data->heredoc_quoted = 1;
			}
			tmp = remove_quotes_token(data->tokens[i + 1]);
			free(data->tokens[i + 1]);
			data->tokens[i + 1] = tmp;
		}
		i++;
	}
}
