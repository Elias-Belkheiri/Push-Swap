/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:25:11 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/25 13:29:40 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack1, t_list **stack2, int a)
{
	t_list	*tmp;

	if (!*stack1)
		return ;
	tmp = (*stack1)->next;
	ft_lstadd_front(stack2, *stack1);
	*stack1 = tmp;
	if (!ft_lstsize(*stack1))
		*stack1 = NULL;
	if (a == 3)
		return ;
	if (!a)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

t_list	*ft_beforelast(t_list *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void	rev_rotate(t_list **stack, int a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*stack)
		return ;
	tmp = ft_lstlast(*stack);
	tmp2 = ft_beforelast(*stack);
	tmp2->next = NULL;
	ft_lstadd_front(stack, tmp);
	if (a == 3)
		return ;
	if (!a)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rotate(t_list **stack, int a)
{
	t_list	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
	if (a == 3)
		return ;
	if (!a)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	swap(t_list **stack, int a)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	if ((*stack)->content < (*stack)->next->content
		|| !*stack)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (a == 3)
		return ;
	if (!a)
		write (1, "sa\n", 3);
	else
		write (1, "sb\n", 3);
}
