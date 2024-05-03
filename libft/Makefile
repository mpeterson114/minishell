NAME = libft.a

#HDRS = libft.h

SRCS = ft_isalpha.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_memset.c\
	ft_memcpy.c\
	ft_atoi.c\
    ft_isalnum.c\
    ft_isascii.c\
    ft_isdigit.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_isprint.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strcpy.c\
	ft_strrchr.c\
	ft_strdup.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strlcat.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	matrixdup.c\
	free_arr.c\
	ft_strndup.c\
	ft_printf/ft_decimal.c\
	ft_printf/ft_hex.c \
	ft_printf/ft_percent.c\
	ft_printf/ft_pointer.c\
	ft_printf/ft_unsigned.c\
	ft_printf/ft_words.c\
	ft_printf/ft_printf.c\
	get_next_line/get_next_line_utils.c\
	get_next_line/get_next_line.c \
	
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
REMOVE = rm -f

%.o: %c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(REMOVE) $(OBJS) 

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
