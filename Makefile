NAME = libft.a

FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS_FILES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(FILES:.c=.o)
BONUS_OBJ = $(BONUS_FILES:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME) 

$(NAME):	$(OBJ)
	@ar rcs $@ $^
	@ranlib $@
	@echo "Successfully made $(NAME)!"

$(OBJ):	$(FILES)
	@gcc $(CFLAGS) -c $(FILES)

bonus: $(BONUS_FILES)
	@gcc $(CFLAGS) -c $(BONUS_FILES)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)
	@echo "Successfully compiled bonus files!"

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@echo "Objects removed successfully!"

fclean:	clean
	@$(RM) $(NAME)
	@echo "Executable removed successfully!"

re:	fclean all
	@echo "Recompiled $(NAME) successfully!"
	
so:
	@gcc -nostartfiles -fPIC $(CFLAGS) -c $(FILES)
	@gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY:	all, bonus, clean, fclean, re
