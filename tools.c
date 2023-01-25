/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:51:01 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/24 11:02:02 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_error()
{
	write(2, "ERROR\n", 6);
	return (1);
}

int is_sorted(t_list *stack)
{
	int	a;

	if (!stack)
		return (0);
	a = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (stack->content < a)
			return (0);
		a = stack->content;
		stack = stack->next;
	}
	return (1);
}

int mouvments_num(int idx, int size)
{
	int middle;

	middle = size / 2;
	if (idx < middle)
		return (idx);
	return (size - idx);
}

void	getSecondMax(t_list *stack, t_min *secondMax, t_min *number2)
{
	int	i;
	i = 0;
	if (!stack || ft_lstsize(stack) == 1)
		return ;
	secondMax->num = number2->num;
	secondMax->idx = number2->idx;
	while (stack)
	{
		if (stack->content != number2->num && stack->content > secondMax->num)
		{
			secondMax->num = stack->content;
			secondMax->idx = i;
		}
		i++;
		stack = stack->next;
	}
}


void	push_to_a(t_list **stack_b, t_list **stack_a, t_min *number)
{
	int size = ft_lstsize(*stack_b);
	if (number->idx <= size / 2)
	{
		while ((*stack_b)->content != number->num)
			rotate(stack_b, 1);
	}
	else
	{
		while ((*stack_b)->content != number->num)
			rev_rotate(stack_b, 1);
	}
	push(stack_b, stack_a, 0);
}

void	get_max(t_list *stack, t_min *max1, t_min *max2)
{
	int	i;

	i = 0;
	max1->num = stack->content;
	max1->idx = 0;
	while (stack)
	{
		if (stack->content > max1->num)
		{
			max2->num = max1->num;
			max2->idx = max1->idx;
			max1->num = stack->content;
			max1->idx = i;
		}
		i++;
		stack = stack->next;
	}
}
