/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:51:01 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/26 16:16:44 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
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

int	mouvments_num(int idx, int size)
{
	int	middle;

	middle = size / 2;
	if (idx < middle)
		return (idx);
	return (size - idx + 1);
}

void	push_to_a(t_list **stack_b, t_list **stack_a, t_min *number)
{
	int	size;

	size = ft_lstsize(*stack_b);
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

int	get_min_max(t_list *stack, int *min, int *max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (min)
		*min = stack->content;
	*max = stack->content;
	while (stack)
	{
		if (min && stack->content < *min)
			*min = stack->content;
		if (stack->content > *max)
		{
			*max = stack->content;
			j = i;
		}
		stack = stack->next;
		i++;
	}
	return (j);
}

void	push_to_a_2(t_list **stack_a, t_list **stack_b, int *count, int n)
{
	if (n)
	{
		if (!(*count) || (*stack_b)->content > ft_lstlast(*stack_a)->content)
		{
			push(stack_b, stack_a, 0);
			rotate(stack_a, 0);
			(*count)++;
		}
		else
			rotate(stack_b, 1);
	}
	else
	{
		if (!(*count) || (*stack_b)->content > ft_lstlast(*stack_a)->content)
		{
			push(stack_b, stack_a, 0);
			rotate(stack_a, 0);
			(*count)++;
		}
		else
			rev_rotate(stack_b, 1);
	}
}
