/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:01:54 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/15 06:29:30 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "structs.h"

# include "libft.h"

# define Y				"\001\033[93m\002"
# define BOLD			"\001\033[1m\002"
# define R				"\001\033[91m\002"
# define P				"\001\033[35m\002"
# define G				"\001\033[0;92m\002"
# define B				"\001\033[0;94m\002"
# define N				"\001\e[0m\002"

# define PROMPT  "\001\033[35m\002Minishell$ \001\e[0m\002"
# define HEREDOC_NAME "/tmp/.minishell_heredoc_"

# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

# define OK 0
# define FAILURE 1

// init_data.c
bool		init_data(t_shell *sh, char **env);
void		init_input_output(t_command *cmd);

// shlvl.c
void		update_shlvl(t_shell *sh);
int			find_env_index(t_shell *sh, char **env_split, int i);
char		**add_line_to_matrix(char **old_matrix, char *line);
void		replace_o_create_env(t_shell *s, char *env_variable);
char		*find_env(t_shell *sh, char *env_key);

// env.c
void		update_pwd(t_shell *sh);
void		add_or_updt_env(t_shell *sh, char *line);
bool		copy_envp(t_shell *sh, char **envp);

// exit.c
void		exit_minishell(t_shell *sh, int exno);

// error.c
int			cmd_error_message(char *command, char *detail, char *error_message,
				int error_nb);
void		syntax_errmsg(char *message, char *quote, int is_quote);

// cleanup.c
void		free_data(t_shell *sh, bool clear_history);
void		close_fds(t_command *cmds, bool close_backups);
void		free_io(t_fds *io);
void		free_ptr(void *ptr);
void		free_ptr_arr(char **tab);

// parser_lexer.c
bool		lexer_and_parser(t_shell *sh);

// tokenization.c
int			tokenization(t_shell *sh, char *str);

// tokenization_utils.c
int			add_word_or_delim(int *i, char *str, int start, t_shell *sh);
int			updt_quote_status(int status, char *str, int i);
int			is_delimiter(char *str, int i);
int			add_word(t_token **token_lst, char *str, int index, int start);
int			add_delim(t_token **token_lst, char *str, int index, int type);

// syntax.c
int			check_syntax2(t_token **token_lst);

// variable.c
int			check_syntax(t_token **tokens);
int			check_variable(t_token **tokens);

// token_lst_utils.c
t_token		*new_token_lst(char *content, char *content_copy, int type, int qs);
void		add_back_tok_lst(t_token **lst, t_token *new_node);
void		lstdelone_token(t_token *lst, void (*del)(void *));
void		lstclear_token(t_token **lst, void (*del)(void *));

//expander.c
int			expander(t_shell *sh, t_token **token_lst);

//find_value.c
bool		var_exists(t_shell *sh, char *var);
char		*find_value(t_token *token, char *str, t_shell *sh);

//find_var.c
char		*find_variable(char *str);
int			variable_length(char *str);
bool		char_is_accept_for_var(char c);

//replace_variable.c
int			replace_variable(t_token **node, char *value, int pos);
void		copy_value(char *new, char *value, int *j);
char		*var_expander_heredoc(t_shell *sh, char *str);
char		*replace_str_heredoc(char *str, char *var_value, int index);

// expander_utils.c
void		copy_value(char *new, char *value, int *j);
char		*get_new_str(char *old, char *value,
				int newsize, int p);

//quotes_handler.c
int			quotes_handler(t_shell *sh);
bool		quotes_are_found(char *str);
int			count_len_without_q(char *str, int count, int i);

//quotes_remover.c
int			remove_quotes(t_token **token_node);

// create_command.c
void		create_commands(t_shell *sh, t_token *token);

// parse_command.c
void		parse_word(t_command **cmd, t_token **token_lst);

// fill_cmd_args_standard.c
int			count_arguments(t_token *temp);
int			fill_command_args(t_token **token_node, t_command *last_cmd);
int			add_args_default_mode(t_token **token_node, t_command *last_cmd);
int			create_cmdargs_standard(t_token **token_node, t_command *last_cmd);
char		**copy_in_new_tab(
				int len, char **new_tab, t_command *last_cmd,
				t_token **tk_node);

// fill_args_echo_mode.c
int			add_args_echo_mode(t_token **token_node, t_command *last_cmd);
int			create_args_echo_mode(t_token **token_node, t_command *last_cmd);
void		remove_empty_var_args(t_token **tokens);

// cmd_lst_utils.c
t_command	*lst_new_cmd(bool value);
void		add_cmd_back(t_command **alst, t_command *new_node);
t_command	*lst_last_cmd(t_command *cmd);
t_command	*lst_first_cmd(t_command *cmd);

// cmd_lst_utils_cleanup.c
void		lst_delone_cmd(t_command *lst, void (*del)(void *));
void		lst_clear_cmd(t_command **lst, void (*del)(void *));

// trunc_parser.c
void		parse_trunc(t_command **last_cmd, t_token **token_lst);
char		*get_relative_path(char *file_to_open);

// input_parser.c
bool		remove_old_file_ref(t_fds *io, bool infile);
void		parse_input(t_command **last_cmd, t_token **token_lst);

// parse_append.c
void		parse_append(t_command **last_cmd, t_token **token_lst);

// parse_heredoc.c
void		parse_heredoc(t_shell *sh, t_command **last_cmd,
				t_token **token_lst);
bool		evaluate_line(t_shell *sh, char **line, t_fds *io, bool *ret);

// parse_heredoc_utils.c
bool		fill_heredoc(t_shell *sh, t_fds *io, int fd);

// parse_pipec
void		parse_pipe(t_command **cmd, t_token **token_lst);

// env_builtins.c
int			count_env_vars(char **env);
int			find_env_index_by_key(char **env, char *var);
char		*get_env_value(char **env, char *var);
bool		is_valid_env_key(char *var);

// env_set.c
bool		add_or_updt_env_var(t_shell *sh, char *key, char *value);
bool		remove_env_var(t_shell *sh, int idx);

// builtins
int			env_builtin(t_shell *sh, char **args);
int			pwd_builtin(t_shell *sh, char **args);
int			echo_builtin(t_shell *sh, char **args);
int			export_builtin(t_shell *sh, char **args);
int			unset_builtin(t_shell *sh, char **args);
int			cd_builtin(t_shell *sh, char **args);
int			exit_builtin(t_shell *sh, char **args);
bool		is_var_no_quotes(t_token *tokens, int index);
char		*remove_extra_spaces(const char *s);

// signal.c
void		ignore_ctrl_backslash(void);
void		signals_awaiting_input(void);
void		signals_ignoring(void);
void		sigquit_non_interactive(void);
void		sigint_non_interactive(void);
void		signals_awaiting_heredoc(void);
void		echoctl(int flag);

// execute.c
int			execute(t_shell *sh);

// command_exec.c
int			command_exec(t_shell *sh, t_command *cmd);
int			execute_builtin(t_shell *sh, t_command *cmd);

// execute_utils.c
bool		cmd_is_dir(char *cmd);
int			check_command_not_found(t_shell *sh, t_command *cmd);

// parse_path.c
char		*get_cmd_path(t_shell *sh, char *cmd);

// pipe.c
bool		create_pipes(t_shell *sh);
bool		set_pipe_fds(t_command *cmds, t_command *curr_cmd);
void		close_pipe_fds(t_command *cmds, t_command *skip_cmd);

// file_io.c
bool		io_check(t_fds *io);
bool		redirect_io(t_fds *io);
bool		restore_io(t_fds *io);

// heredoc.c
bool		get_heredoc(t_shell *sh, t_fds *io);

// debug.c
void		print_cmd_lst(t_shell *sh);
void		print_tokens(t_token **tokens);

// utils and others
void		rl_replace_line(const char *text, int clear_undo);
char		*strjoin_free_s1(char *s1, char const *s2);
int			is_space(char c);
void		remove_last_newline(char *line);

#endif