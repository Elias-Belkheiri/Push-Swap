/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:05:49 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/09 14:39:54 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static t_list	*ft_cpy(t_list *lst, t_list *head, void *(*f)(int))
// {
// 	t_list	*nw_lst;
// 	t_list	*ptr;

// 	ptr = lst;
// 	while (ptr)
// 	{
// 		if (!head)
// 		{
// 			head = ft_lstnew(f(ptr->content));
// 			if (!head)
// 				return (NULL);
// 			nw_lst = head;
// 		}
// 		else
// 		{
// 			nw_lst->next = ft_lstnew(f(ptr->content));
// 			if (!nw_lst->next)
// 				return (NULL);
// 			nw_lst = nw_lst->next;
// 		}
// 		ptr = ptr->next;
// 	}
// 	return (head);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(int))
// {
// 	t_list	*head;

// 	head = NULL;
// 	if (lst && f && del)
// 	{
// 		head = ft_cpy(lst, head, f);
// 		if (!head)
// 			ft_lstclear(&head, del);
// 		return (head);
// 	}
// 	return (NULL);
// }

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prv;

	prv = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = NULL;
	while (prv->next)
		prv = prv->next;
	prv->next = new;
}
