/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:31:37 by tafonso           #+#    #+#             */
/*   Updated: 2026/03/05 12:08:09 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	env_size(t_env *env)
{
	int	size;

	size = 0;
	while (env)
	{
		size++;
		env = env->next;
	}
	return (size);
}

static t_env	**env_to_array(t_env *env)
{
	int		size;
	t_env	**array;
	int		i;

	size = env_size(env);
	array = malloc(sizeof(t_env *) * (size + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (env)
	{
		array[i] = env;
		i++;
		env = env->next;
	}
	array[i] = NULL;
	return (array);
}

static void	sort_env_array(t_env **array)
{
	int		i;
	int		j;
	t_env	*temp;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_strcmp(array[i]->key, array[j]->key) > 0)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	is_valid_varname(char *str)
{
	int	i;

	i = 0;
	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	print_export(t_env *env)
{
	t_env	**env_array;
	int		i;

	env_array = env_to_array(env);
	sort_env_array(env_array);
	i = 0;
	while (env_array[i])
	{
		if (ft_strcmp(env_array[i]->key, "_") == 0)
		{
			i++;
			continue ;
		}
		printf("declare -x %s", env_array[i]->key);
		if (env_array[i]->value)
			printf("=\"%s\"", env_array[i]->value);
		printf("\n");
		i++;
	}
	free(env_array);
}
