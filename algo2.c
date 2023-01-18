/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:25:16 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/18 14:41:03 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_2(t_list *stack, t_min *number, int min)
{
	int	i;

	number->num = stack->content;
	i = 0;
	while (stack)
	{
		if (stack->content < min + 12)
		{
			number->num = stack->content;
			number->idx = i;
			return (1);
		}
		i++;
		stack = stack->next;
	}
	return (0);
}

int getMinMax(t_list *stack, int *min, int *max)
{
	int	i;

	i = 0;
	if (min)
    	*min = stack->content;
    *max = stack->content;
    while (stack)
    {
        if (min && stack->content < *min)
            *min = stack->content;
        if (stack->content > *max)
            *max = stack->content;
        stack = stack->next;
		i++;
    }
	return (i);
}

int mouvments_num(int idx, int size)
{
	int middle;

	middle = size / 2;
	if (idx > middle)
		return (idx);
	return (size - idx);
}

void	check_idx_push(t_list **stack_a, t_list **stack_b, t_min *number, int size)
{
	int middle;

	middle = size / 2;
	if (number->idx < middle)
	{
		while ((*stack_a)->content != number->num)
			rotate(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->content != number->num)
			rev_rotate(stack_a, 0);
	}
	push(stack_a, stack_b, 1);
}

int	check_push(t_list **stack_a, t_list **stack_b, t_min *firstMin, t_min *secondMin)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (mouvments_num(firstMin->idx, size) < mouvments_num(secondMin->idx, size))
		check_idx_push(stack_a, stack_b, firstMin, size);
	else
		check_idx_push(stack_a, stack_b, secondMin, size);
	return (1);
}

int    check_range(t_list **stack_a, t_list **stack_b, int min)
{
	int		i;
	int		indice;
    t_list *stack;
	t_min	firstMin;
	t_min	secondMin;

	stack = *stack_a;
	indice = find_min_2(stack, &firstMin, min);
	find_min_2(stack, &secondMin, min);
	i = 0;
	while (stack)
	{
		if (stack->content < min + 12)
		{
			secondMin.num = stack->content;
			secondMin.idx = i;
			indice++;
		}
		stack = stack->next;
	}
	if (indice)
		return (check_push(stack_a, stack_b, &firstMin, &secondMin));
	return (0);
}

void	reset_b(t_list **stack_a, t_list **stack_b)
{
	t_min	max;
	int		size;

	size = ft_lstsize(*stack_b);
	max.idx = getMinMax(*stack_b, NULL, &max.num);
	if (max.idx < size / 2)
	{
		while ((*stack_b)->content != max.num)
			rotate(stack_b, 1);
	}
	else
	{
		while ((*stack_b)->content != max.num)
			rev_rotate(stack_b, 1);
	}
	push(stack_b, stack_a, 0);
}

void    algo3(t_list **stack_a, t_list **stack_b)
{
    int min;
    int max;
    int p;

    getMinMax(*stack_a, &min, &max);
    while (ft_lstsize(*stack_a))
    {
        p = check_range(stack_a, stack_b, min);
        while (p && *stack_a)
            p = check_range(stack_a, stack_b, min);
        min += 12;
    }
	while (ft_lstsize(*stack_b))
		reset_b(stack_a, stack_b);
}
