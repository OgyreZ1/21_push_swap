NAME =	push_swap

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD

RM =	rm -rf

SRC =   ./src/push_swap.c \
		./src/sort.c \
		./src/sort_utils.c \
		./src/parser.c \
		./src/operations_r.c \
		./src/operations_rr.c \
		./src/operations_s_p.c \
		./src/list1.c \
		./src/list2.c \

INC = 	-I libft/libft.h 	\
		-I src/push_swap.h \

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :		
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			make -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP) $(OBJS_B) $(DEP_B)
			make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C libft/

re: 		fclean all

-include $(DEP)
-include $(DEP_B)