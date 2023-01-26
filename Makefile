NAME				= 	push_swap

SRCS				=	push_swap.c algo.c algo2.c tools.c ./srcs/ft_strncmp.c ./srcs/check.c ./srcs/ft_lsttools.c ./srcs/ft_lsttools2.c ./srcs/ft_split.c ./srcs/ft_strlen.c ./srcs/ft_substr.c ./srcs/ft_strlcpy.c ./srcs/ft_atoi.c ./srcs/ft_strdup.c ./srcs/ft_free_all_mfs.c operations.c operations2.c 

BONUS_SRCS			=	checker_bonus.c tools.c ./srcs/ft_strncmp.c ./srcs/get_next_line.c ./srcs/get_next_line_utils.c ./srcs/check.c ./srcs/ft_lsttools.c ./srcs/ft_lsttools2.c ./srcs/ft_split.c ./srcs/ft_strlen.c ./srcs/ft_substr.c ./srcs/ft_strlcpy.c ./srcs/ft_atoi.c ./srcs/ft_strdup.c ./srcs/ft_free_all_mfs.c operations.c operations2.c

CC					= 	cc

CFLAGS				=	-Wall -Wextra -Werror

NAME_BONUS		    = checker

all					:  ${NAME}

bonus				:  ${NAME_BONUS}
						
${NAME}				:  ${SRCS}
						${CC} -g ${CFLAGS} ${SRCS} -o ${NAME}

${NAME_BONUS}		:  ${BONUS_SRCS}
						${CC} ${CFLAGS} ${BONUS_SRCS} -o ${NAME_BONUS}

clean				:
						rm -f ${NAME}

fclean				:  clean
						rm -f ${NAME_BONUS} ${BONUS_NAME}

re 					: 	fclean all 