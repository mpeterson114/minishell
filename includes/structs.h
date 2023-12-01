/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 06:08:51 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/14 10:49:04 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

extern int	g_sig;

typedef struct s_token
{	
	char			*content;
	char			*cc;
	bool			is_var;
	int				type;
	int				q_status;
	int				index;
	bool			has_quotes;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_fds
{
	char	*infile;
	char	*outfile;
	char	*heredoc_del;
	bool	heredoc_quotes;
	int		fd_in;
	int		fd_out;
	int		stdin_backup;
	int		stdout_backup;
	bool	error_msg;
}	t_fds;

typedef struct s_command
{
	char				*command;
	char				*path;
	char				**args;
	bool				pipe_output;
	int					*pipe_fd;
	t_fds				*fds;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

typedef struct s_shell
{
	t_token		*token;
	char		*line;
	char		**env;
	char		*pwd;
	char		*old_pwd;
	t_command	*cmd;
	pid_t		pid;
}	t_shell;

enum e_token_types {
	SPACES = 1,
	WORD,
	VAR,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND,
	END
};

enum e_quotes {
	QOK,
	SQ,
	DQ
};
#endif
