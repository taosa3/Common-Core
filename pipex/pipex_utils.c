/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:44:24 by tafonso           #+#    #+#             */
/*   Updated: 2025/09/10 16:40:56 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin3(char *str1, char *separator, char *str2)
{
	char	*temp;
	char	*final;

	temp = ft_strjoin(str1, separator);
	final = ft_strjoin(temp, str2);
	free(temp);
	return (final);
}

static char	*get_path_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*search_path(char **paths, char *cmd)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin3(paths[i], "/", cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

static char	*find_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_env = get_path_from_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (search_path(paths, cmd));
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		free_split(args);
		leave_program("Error: Invalid command", 0);
	}
	cmd_path = find_command_path(args[0], envp);
	if (!cmd_path)
	{
		free_split(args);
		leave_program("Error: Command not found", 0);
	}
	execve(cmd_path, args, envp);
	free(cmd_path);
	free_split(args);
	leave_program("Error: execve failed", 0);
}
