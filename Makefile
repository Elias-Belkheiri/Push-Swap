NAME				= 	push_swap

SRCS				=	push_swap.c algo.c tools.c ./srcs/ft_strncmp.c ./srcs/check.c ./srcs/ft_lsttools.c ./srcs/ft_lsttools2.c ./srcs/ft_split.c ./srcs/ft_strlen.c ./srcs/ft_substr.c ./srcs/ft_strlcpy.c ./srcs/ft_atoi.c ./srcs/ft_strdup.c ./srcs/ft_free_all_mfs.c operations.c

BONUS_SRCS			=	checker.c algo.c tools.c ./srcs/ft_strncmp.c ./srcs/get_next_line.c ./srcs/get_next_line_utils.c ./srcs/check.c ./srcs/ft_lsttools.c ./srcs/ft_lsttools2.c ./srcs/ft_split.c ./srcs/ft_strlen.c ./srcs/ft_substr.c ./srcs/ft_strlcpy.c ./srcs/ft_atoi.c ./srcs/ft_strdup.c ./srcs/ft_free_all_mfs.c operations.c

CC					= 	cc

CFLAGS				=	-Wall -Wextra -Werror

bonus_name			=	checker

all					:  ${NAME}

bonus				:  ${BONUS_SRCS}
						${CC} ${CFLAGS} ${BONUS_SRCS} -o ${bonus_name}

${NAME}				:  ${SRCS}
						${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean				:
						rm -f ${NAME}

fclean				:  clean
						rm -f ${NAME_BONUS} ${bonus_name}

re 					: 	fclean all 