NAME				= 	push_swap


SRCS				=	push_swap.c algo.c ./srcs/check.c ./srcs/ft_lsttools.c ./srcs/ft_lsttools2.c ./srcs/ft_split.c ./srcs/ft_strlen.c ./srcs/ft_substr.c ./srcs/ft_strlcpy.c ./srcs/ft_atoi.c ./srcs/ft_strdup.c ./srcs/ft_free_all_mfs.c operations.c

CC					= 	cc

CFLAGS				=	-Wall -Wextra -Werror

all					:  ${NAME}


${NAME}				:  ${SRCS}
						${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean				:
						rm -f ${NAME}

fclean				:  clean
						rm -f ${NAME_BONUS}

re 					: 	fclean all 