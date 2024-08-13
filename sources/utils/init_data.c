#include "minishell.h"

/* init_wds:
*	Initializes working directory variables as a safeguard against
*	environment PWD and OLDPWD being unset or otherwise not present
*	in the environment. Used for cd builtin.
*	Returns true if successful, false in case of error.
*/
static bool	init_wds(t_shell *sh)
{
	char	buff[PATH_MAX];
	char	*wd;

	wd = getcwd(buff, PATH_MAX);
	sh->pwd = ft_strdup(wd);
	if (!sh->pwd)
		return (false);
	if (find_env_index_by_key(sh->env, "OLDPWD") != -1)
	{
		sh->old_pwd = ft_strdup(get_env_value(sh->env,
					"OLDPWD"));
		if (!sh->old_pwd)
			return (false);
	}
	else
	{
		sh->old_pwd = ft_strdup(wd);
		if (!sh->old_pwd)
			return (false);
	}
	return (true);
}

/* create_env:
*	Initializes a data variable with the contents of the environment
*	variables inherited from the original shell.
*	Returns 0 on failure, 1 on success.
*/
bool	create_env(t_shell *sh)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free(pwd);
		return (false);
	}
	sh->env = malloc(sizeof(char *) * 4);
	if (!sh->env)
		return (false);
	sh->env[0] = ft_strjoin("PWD=", pwd);
	sh->env[1] = ft_strdup("SHLVL=1");
	sh->env[2] = ft_strdup("_=/usr/bin/env");
	if (!sh->env[0] || !sh->env[1] || !sh->env[2])
		return (false);
	sh->env[3] = NULL;
	free(pwd);
	return (true);
}

bool	init_env(t_shell *sh, char **env)
{
	if (!*env)
	{
		if (!create_env(sh))
			return (false);
	}
	else
	{
		if (!copy_envp(sh, env))
			return (false);
	}
	return (true);
}

/* init_data:
*	Initializes the data structure used in parsing and executing user input.
*	Returns true if successful, false in case of error.
*/
bool	init_data(t_shell *sh, char **env)
{
	if (!init_env(sh, env))
	{
		cmd_error_message("Error", NULL, \
		"Failed to initialize environment variables", errno);
		return (false);
	}
	if (!init_wds(sh))
	{
		cmd_error_message("Error", NULL, \
		"Failed to initialize working directories", errno);
		return (false);
	}
	sh->token = NULL;
	sh->line = NULL;
	sh->cmd = NULL;
	sh->pid = -1;
	g_sig = 0;
	return (true);
}

void	init_input_output(t_command *cmd)
{
	if (!cmd->fds)
	{
		cmd->fds = malloc(sizeof * cmd->fds);
		if (!cmd->fds)
			return ;
		cmd->fds->infile = NULL;
		cmd->fds->outfile = NULL;
		cmd->fds->heredoc_del = NULL;
		cmd->fds->heredoc_quotes = false;
		cmd->fds->fd_in = -1;
		cmd->fds->fd_out = -1;
		cmd->fds->stdin_backup = -1;
		cmd->fds->stdout_backup = -1;
		cmd->fds->error_msg = false;
	}
}
