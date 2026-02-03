NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c position.c linked_data.c ft_sort.c \
	   actions.c check_acending.c check_errors.c \
	   ft_split.c 

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 
  
clean:
	rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re