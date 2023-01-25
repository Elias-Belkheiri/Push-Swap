/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:25:16 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/23 14:56:25 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getMinMax(t_list *stack, int *min, int *max)
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

void	check_idx_push(t_list **stack_a, t_list **stack_b, t_min *number)
{
	int middle;

	if (!*stack_a)
		return ;
	middle = ft_lstsize(*stack_a) / 2;
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
		check_idx_push(stack_a, stack_b, firstMin);
	else
		check_idx_push(stack_a, stack_b, secondMin);
	return (1);
}

int	lastMin(t_list *stack, t_min *number, int min, int a)
{
	int	i;
	int	indice;

	i = 0;
	indice = 0;
	while (stack)
	{
		if (stack->content < min + a)
		{
			number->num = stack->content;
			number->idx = i;
			indice++;
		}
		i++;
		stack = stack->next;
	}
	return (indice);
}

int	firstMin(t_list *stack, t_min *number, int min, int a)
{
	int	i;

	number->num = stack->content;
	i = 0;
	while (stack)
	{
		if (stack->content < min + a)
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

int    check_range(t_list **stack_a, t_list **stack_b, int min, int a)
{
	int	indice;
    t_list *stack;
	t_min	first_Min;
	t_min	second_Min;

	stack = *stack_a;
	indice = firstMin(stack, &first_Min, min, a);
	indice += lastMin(*stack_a, &second_Min, min, a);
	if (indice)
	{
		check_push(stack_a, stack_b, &first_Min, &second_Min);
		if ((*stack_b)->content > min + (a / 2))
			rotate(stack_b, 1);
		return (1);
	}
	return (0);
}

void	reset_b(t_list **stack_a, t_list **stack_b)
{
	t_min	firstMax;
	t_min	secondMax;
	int		size;

	size = ft_lstsize(*stack_b);
	firstMax.idx = getMinMax(*stack_b, NULL, &firstMax.num);
	if (ft_lstsize(*stack_b) == 1)
	{
		push(stack_b, stack_a, 0);
		return ;
	}
	getSecondMax(*stack_b, &secondMax, firstMax.num);
	if (mouvments_num(firstMax.idx, size) < mouvments_num(secondMax.idx, size))
		push_to_a(stack_b, stack_a, &firstMax, size);
	else
	{
		push_to_a(stack_b, stack_a, &secondMax, size);
		push_to_a(stack_b, stack_a, &firstMax, size);
		swap(stack_a, 0);
	}
	// if (firstMax.idx < size / 2)
	// {
	// 	while ((*stack_b)->content != firstMax.num)
	// 		rotate(stack_b, 1);
	// }
	// else
	// {
	// 	while ((*stack_b)->content != firstMax.num)
	// 		rev_rotate(stack_b, 1);
	// }
	// push(stack_b, stack_a, 0);
}

void    algo3(t_list **stack_a, t_list **stack_b)
{
    int min;
    int max;
    int p;
	int	a;

    getMinMax(*stack_a, &min, &max);
	a = (max - min) / 4;
    while (ft_lstsize(*stack_a))
    {
        p = check_range(stack_a, stack_b, min, a);
        while (p && *stack_a)
            p = check_range(stack_a, stack_b, min, a);
        min += a;
    }
	while (ft_lstsize(*stack_b))
	{
		printf("---------\n");
		print_list(*stack_b);
		reset_b(stack_a, stack_b);
	}
}