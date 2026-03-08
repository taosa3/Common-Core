/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_without_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:05:03 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/06 23:13:13 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_cmd_path(t_cmd *cmd, t_data *data, char *cmd_path)
{
	if (!cmd_path || ft_strcmp(cmd->args[0], ".") == 0
		|| ft_strcmp(cmd->args[0], "..") == 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd->args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		free(cmd_path);
		free_all(data);
		return (127);
	}
	if (is_directory(cmd_path))
	{
		ft_putstr_fd(cmd->args[0], STDERR_FILENO);
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
		free(cmd_path);
		free_all(data);
		return (126);
	}
	if (access(cmd_path, X_OK) != 0)
	{
		perror(cmd->args[0]);
		free(cmd_path);
		return (free_all(data), 126);
	}
	return (0);
}

static void	child_setup_and_exec(t_data *data, t_cmd *cmd, char **envp)
{
	char	*cmd_path;
	int		err;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	handle_redirections(cmd, data, envp);
	if (cmd->args && cmd->args[0])
	{
		cmd_path = find_command_path(cmd->args[0], envp);
		err = check_cmd_path(cmd, data, cmd_path);
		if (err)
		{
			free_envp(envp);
			exit(err);
		}
		execve(cmd_path, cmd->args, envp);
		perror("execve");
		free(cmd_path);
		free_envp(envp);
		free_all(data);
		exit(EXIT_FAILURE);
	}
	free_all(data);
	exit(EXIT_SUCCESS);
}

static void	parent_wait_and_cleanup(t_data *data, pid_t pid, t_cmd *cmd,
									char **envp)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, ctrlc_handler);
	signal(SIGQUIT, SIG_IGN);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		ft_putendl_fd("Quit (core dumped)", 2);
		data->last_exit_status = 128 + SIGQUIT;
	}
	if (WIFEXITED(status))
		data->last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		data->last_exit_status = 128 + WTERMSIG(status);
	if (cmd->heredoc && cmd->infile_fd > 0)
	{
		close(cmd->infile_fd);
		cmd->infile_fd = -1;
	}
	free_envp(envp);
}

void	exec_without_pipes(t_data *data, t_cmd *cmd)
{
	pid_t	pid;
	char	**envp;

	if (!cmd)
		return ;
	if ((!cmd->args || !cmd->args[0]) && !cmd->heredoc)
	{
		data->last_exit_status = handle_null_redirections(cmd);
		return ;
	}
	if (process_heredocs(cmd, data) == -1)
		return ;
	envp = env_list_to_envp(data->env_list);
	if (!envp)
		return ;
	pid = fork();
	if (pid < 0)
	{
		perror ("fork");
		free_envp(envp);
		return ;
	}
	if (pid == 0)
		child_setup_and_exec(data, cmd, envp);
	parent_wait_and_cleanup(data, pid, cmd, envp);
}
