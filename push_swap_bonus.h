/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:25:55 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/27 15:44:05 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
typedef struct s_min_idx
{
	int	num;
	int	idx;
}	t_min;
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char *str1, char *str2);
char		*ft_strchr(const char *str, int c);
size_t		get_len(char *str);
long long	ft_atoi(const char *str);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_free_all_mfs(char **str);
int			ft_clear(char **arg, t_list **stack_a);
char		**ft_split(char const *s, char c);
int			ft_strlcpy(char *dst, const char *src, int dstsize);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *ptr);
int			check_and_push(char *arg1, t_list **stack_a);
void		swap(t_list **stack, int a);
void		push(t_list **stack1, t_list **stack2, int a);
void		print_list(t_list *stack_a);
void		ss(t_list **stack1, t_list **stack2, int a);
void		rotate(t_list **stack, int a);
void		rev_rotate(t_list **stack, int a);
int			check_range(t_list **stack_a, t_list **stack_b, int min, int a);
int			check_push(t_list **stack_a, t_list **stack_b,
				t_min *firstMin, t_min *secondMin);
void		check_idx_push(t_list **stack_a, t_list **stack_b, t_min *number);
int			ft_error(t_list **stack_a, t_list **stack_b);
int			is_sorted(t_list *stack);
void		algo1(t_list **stack_a, int a);
void		algo2(t_list **stack_a, t_list **stack_b);
void		algo3(t_list **stack_a, t_list **stack_b);
void		rr(t_list **stack1, t_list **stack2, int a);
void		rrr(t_list **stack1, t_list **stack2, int a);
void		find_min(t_list *stack, t_min *min);
int			mouvments_num(int idx, int size);
void		push_to_a(t_list **stack_b, t_list **stack_a, t_min *number);
int			get_min_max(t_list *stack, int *min, int *max);
void		push_to_a_2(t_list **stack_a, t_list **stack_b, int *count, int n);
int			check_and_execute_instructions(char **instructions, t_list **stack_a,
				t_list **stack_b);
char		**read_from_si(void);
void		check_stacks(t_list *stack_a, t_list *stack_b);

#endif