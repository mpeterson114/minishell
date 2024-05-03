# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 16:00:36 by ilzhabur          #+#    #+#              #
#    Updated: 2024/04/11 15:27:11 by mpeterso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[0;92m
BLUE		=	\033[0;94m
YELLOW		=	\033[0;93m
NC			=	\033[0m

NAME	= minishell
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
SRC	= 	main.c \
			env/env.c \
			env/env_builtins.c \
			env/env_utils.c \
			env/shlvl.c \
			lexer/parser_lexer.c \
			lexer/tokenization.c \
			lexer/tokenization_utils.c \
			lexer/variable.c \
			lexer/syntax.c \
			lexer/token_lst_utils.c \
			expansion/expander.c \
			expansion/expander_utils.c \
			expansion/find_var.c \
			expansion/quotes_handler.c \
			expansion/quotes_remover.c \
			expansion/find_value.c \
			expansion/replace_variable.c \
			parser/create_commands.c \
			parser/word_parser.c \
			parser/fill_args_echo.c \
			parser/fill_cmd_args_standard.c \
			parser/input_parser.c \
			parser/trunc_parser.c \
			parser/append_parser.c \
			parser/heredoc_parser.c \
			parser/heredoc_parser_utils.c \
			parser/pipe_parser.c \
			parser/cmd_lst_utils.c \
			parser/cmd_lst_utils_cleanup.c \
			builtins/export_builtin.c \
			builtins/unset_builtin.c \
			builtins/cd_builtin.c \
			builtins/env_builtin.c \
			builtins/pwd_builtin.c \
			builtins/echo_builtin.c \
			builtins/echo_builtin2.c \
			builtins/exit_builtin.c \
			execution/execute.c \
			execution/command_exec.c \
			execution/execute_utils.c \
			execution/parse_path.c \
			redirections/pipe.c \
			redirections/file_io.c \
			utils/exit.c \
			utils/error.c \
			utils/init_data.c \
			utils/cleanup.c \
			signals/signal.c \
			signals/signal_non_inter.c \
			debug/debug.c \
			utils/is_functions.c \
			utils/ft_strjoin_free.c  
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I $(INC_PATH) -I $(LIBFT_PATH)
RM		= rm -rf
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a
LDFLAGS		= -L/Users/$(USER)/.brew/opt/readline/lib 
CPPFLAGS	= -I/Users/$(USER)/.brew/opt/readline/include 

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 
	@mkdir -p $(OBJ_PATH)/builtins 
	@mkdir -p $(OBJ_PATH)/lexer 
	@mkdir -p $(OBJ_PATH)/expansion
	@mkdir -p $(OBJ_PATH)/parser 
	@mkdir -p $(OBJ_PATH)/testing 
	@mkdir -p $(OBJ_PATH)/env 
	@mkdir -p $(OBJ_PATH)/execution 
	@mkdir -p $(OBJ_PATH)/utils 
	@mkdir -p $(OBJ_PATH)/redirections
	@mkdir -p $(OBJ_PATH)/signals
	@mkdir -p $(OBJ_PATH)/debug

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(YELLOW)⌛ Compiling source files ⌛ $(NC) → $< "
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	
$(NAME): $(OBJS)
		@stty -echoctl
		@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(LDFLAGS) $(CPPFLAGS) -lreadline
		@echo "$(GREEN)$(NAME) is generated! ✅ $(NC)\n"

$(LIBFT):
	@make -C $(LIBFT_PATH) --silent
	
clean:
		@$(RM) $(OBJ_PATH) 
		@make -C libft clean 
		@echo "${BLUE}All .o files are erased! ✔$(NC)\n"
		
fclean: 		clean 
				@$(RM) $(NAME)
				@make -C libft fclean 
				@echo "${BLUE}$(NAME) is erased! ✓$(NC)\n"

re: 			fclean all
				@echo "$(BLUE)Remake done ✔\n$(NC)"

.PHONY: all re clean fclean