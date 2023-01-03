CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = ./tools/pusha.c\
	./tools/pushb.c\
	./tools/rotate_a.c\
	./tools/rotate_b.c\
	./tools/rotateab.c\
	./tools/reverse_rotate_stack_a.c\
	./tools/reverse_rotate_stack_b.c\
	./tools/reverse_rotateab.c\
	./tools/swapa.c\
	./tools/swapb.c\
	./tools/swapab.c\
	./lib_lst/ft_atoi.c\
	./lib_lst/ft_split.c\
	./lib_lst/ft_lstadd_back_bonus.c\
	./lib_lst/ft_lstadd_front_bonus.c\
	./lib_lst/ft_lstclear_bonus.c\
	./lib_lst/ft_lstlast_bonus.c\
	./lib_lst/ft_lstnew_bonus.c\
	./lib_lst/ft_lstsize_bonus.c\
	./lib_lst/ft_strdup.c\
	./lib_lst/ft_strlen.c\
	sort3.c\
	sort5.c\
	ultimate_sorter.c\
	push_swap.c \
	searching_tools.c \
	advanced_searcher.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

czar: all clean

.PHONY: all clean fclean re