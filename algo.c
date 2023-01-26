/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:43:15 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/26 16:10:16 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo1(t_list **stack_a, int a)
{
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->content > ft_lstlast(*stack_a)->content)
			rotate(stack_a, a);
		else if ((*stack_a)->content > (*stack_a)->next->content)
			swap(stack_a, a);
		else
			rev_rotate(stack_a, a);
	}
}

void	find_min(t_list *stack, t_min *min)
{
	int	i;

	if (!stack)
		return ;
	min->num = stack->content;
	i = 0;
	while (stack)
	{
		if (stack->content < min->num)
		{
			min->num = stack->content;
			min->idx = i;
		}
		i++;
		stack = stack->next;
	}
}

void	algo2(t_list **stack_a, t_list **stack_b)
{
	t_min	min;

	while (ft_lstsize(*stack_a) != 3)
	{
		find_min(*stack_a, &min);
		if ((*stack_a)->content == min.num)
			push(stack_a, stack_b, 1);
		else if (min.idx > (ft_lstsize(*stack_a) / 2))
		{
			while ((*stack_a)->content != min.num)
				rev_rotate(stack_a, 0);
			push(stack_a, stack_b, 1);
		}
		else
		{
			while ((*stack_a)->content != min.num)
				rotate(stack_a, 0);
			push(stack_a, stack_b, 1);
		}
	}
	algo1(stack_a, 0);
	push(stack_b, stack_a, 0);
	push(stack_b, stack_a, 0);
}

void	reset_b(t_list **stack_a, t_list **stack_b, int *count)
{
	t_min	max1;
	int		size;

	size = ft_lstsize(*stack_b);
	max1.idx = get_min_max(*stack_b, NULL, &max1.num);
	if (*count && ft_lstlast(*stack_a)->content > max1.num)
	{
		rev_rotate(stack_a, 0);
		(*count)--;
		return ;
	}
	if (max1.idx < size / 2)
	{
		while ((*stack_b)->content != max1.num)
			push_to_a_2(stack_a, stack_b, count, 1);
	}
	else
	{
		while ((*stack_b)->content != max1.num)
			push_to_a_2(stack_a, stack_b, count, 0);
	}
	push(stack_b, stack_a, 0);
}

void	algo3(t_list **stack_a, t_list **stack_b)
{
	static int	count;
	int			min;
	int			max;
	int			p;
	int			a;

	get_min_max(*stack_a, &min, &max);
	if (ft_lstsize(*stack_a) <= 250)
		a = (max - min) / 4;
	else
		a = (max - min) / 10;
	while (ft_lstsize(*stack_a))
	{
		p = check_range(stack_a, stack_b, min, a);
		while (p && *stack_a)
			p = check_range(stack_a, stack_b, min, a);
		min += a;
	}
	while (ft_lstsize(*stack_b))
		reset_b(stack_a, stack_b, &count);
	while (count--)
		rev_rotate(stack_a, 0);
}
