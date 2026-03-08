/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:04:07 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/06 22:41:10 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*expand_heredoc_dollar(char *res, const char *line,
			int *i, t_data *data)
{
	char	*tmp;
	char	*var;
	int		start;

	if (line[*i + 1] == '?')
		return (*i += 2,
			ft_strjoin_free_expand(res,
				ft_itoa(data->last_exit_status), 1, 1));
	if (line[*i + 1] == '$')
		return (ft_putstr_fd("minishell: $$ is not supported "
				"(forbidden function)\n", STDERR_FILENO), *i += 2,
			ft_strjoin_free_expand(res, ft_strdup(""), 1, 1));
	if (!ft_isalpha(line[*i + 1]) && line[*i + 1] != '_')
		return (ft_strjoin_free_expand(res,
				ft_strndup(&line[(*i)++], 1), 1, 1));
	start = ++(*i);
	while (line[*i] && (ft_isalnum(line[*i]) || line[*i] == '_'))
		(*i)++;
	var = ft_strndup(&line[start], *i - start);
	tmp = get_env_value(var, data->env_list);
	free(var);
	if (tmp)
		res = ft_strjoin_free_expand(res, ft_strdup(tmp), 1, 1);
	return (res);
}

void	write_heredoc(char *line, int fd, t_data *data)
{
	char	*expanded;

	if (!data->heredoc_quoted)
	{
		expanded = expand_heredoc_line(line, data);
		ft_putendl_fd(expanded, fd);
		free(expanded);
	}
	else
		ft_putendl_fd(line, fd);
	free(line);
}

char	*expand_heredoc_line(const char *line, t_data *data)
{
	char	*result;
	int		i;

	if (!line)
		return (NULL);
	result = ft_strdup("");
	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			result = expand_heredoc_dollar(result, line, &i, data);
			continue ;
		}
		result = ft_strjoin_free_expand(result, ft_strndup(&line[i++],
					1), 1, 1);
	}
	return (result);
}
