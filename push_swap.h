/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:29:30 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/10 11:31:27 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

long long	ft_atoi(const char *str);
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(int));
void	ft_free_all_mfs(char **str);
char	**ft_split(char const *s, char c);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *ptr);
int		check_and_push(char *arg1, t_list  **stack_a);
void    swap(t_list **stack, int a);
void	push(t_list **stack1, t_list **stack2, int a);
void	print_list(t_list *stack_a);
void	ss(t_list **stack1, t_list **stack2);
void	rotate(t_list **stack, int a);
void	rev_rotate(t_list **stack, int a);
void	algo(t_list **stack_a, t_list **stack_b);

#endif
