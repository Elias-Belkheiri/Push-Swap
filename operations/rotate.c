/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:41:17 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/09 14:56:09 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_beforelast(t_list *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void	rotate(t_list **stack)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = ft_lstlast(*stack);
	tmp2 = ft_beforelast(*stack);
	tmp2->next = NULL;
	ft_lstadd_front(stack, tmp);
}