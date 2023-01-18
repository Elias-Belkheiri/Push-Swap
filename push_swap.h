/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:29:30 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/18 13:34:37 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void		ft_lstiter(t_list *lst, void (*f)(void *));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(int));
void		ft_free_all_mfs(char **str);
char		**ft_split(char const *s, char c);
int			ft_strlcpy(char *dst, const char *src, int dstsize);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *ptr);
int			check_and_push(char *arg1, t_list  **stack_a);
void    	swap(t_list **stack, int a);
void		push(t_list **stack1, t_list **stack2, int a);
void		print_list(t_list *stack_a);
void		ss(t_list **stack1, t_list **stack2, int a);
void		rotate(t_list **stack, int a);
void		rev_rotate(t_list **stack, int a);
void		algo(t_list **stack_a, t_list **stack_b);
int			ft_error();
int			is_sorted(t_list *stack);
void		algo1(t_list **stack_a, int a);
void		algo2(t_list **stack_a, t_list **stack_b);
void		algo3(t_list **stack_a, t_list **stack_b);
void		rr(t_list **stack1, t_list **stack2, int a);
void		rrr(t_list **stack1, t_list **stack2, int a);

#endif
