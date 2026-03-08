/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:26:41 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/06 22:04:46 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*remove_quotes_token(const char *str)
{
	char	*res;
	int		i;
	int		j;
	int		in_single;
	int		in_double;

	res = malloc(ft_strlen(str) + 1);
	i = 0;
	j = 0;
	in_single = 0;
	in_double = 0;
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (str[i] == '"' && !in_single)
			in_double = !in_double;
		else
			res[j++] = str[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	remove_quotes_args(t_cmd *cmd)
{
	t_cmd	*current;
	char	*tmp;
	int		i;

	current = cmd;
	while (current)
	{
		i = 0;
		if (current->args)
		{
			while (current->args[i])
			{
				tmp = remove_quotes_token(current->args[i]);
				free(current->args[i]);
				current->args[i] = tmp;
				i++;
			}
		}
		current = current->next;
	}
}

static char	*expand_token(const char *token, t_data *data)
{
	char	*result;
	int		i;

	i = 0;
	data->in_single = 0;
	data->in_double = 0;
	result = ft_strdup("");
	while (token[i])
		process_char(token, data, &result, &i);
	return (result);
}

static int	is_heredoc_delimiter(char **tokens, int i)
{
	if (i > 0 && ft_strcmp(tokens[i - 1], "<<") == 0)
		return (1);
	return (0);
}

void	expand_variables(t_data *data)
{
	int		i;
	char	*expanded;

	i = 0;
	while (data->tokens[i])
	{
		if (is_heredoc_delimiter(data->tokens, i))
		{
			i++;
			continue ;
		}
		expanded = expand_token(data->tokens[i], data);
		free(data->tokens[i]);
		if (expanded[0] == '\0' && !data->in_single && !data->in_double)
		{
			free(expanded);
			remove_token_index(data->tokens, i);
			continue ;
		}
		data->tokens[i] = expanded;
		i++;
	}
}
