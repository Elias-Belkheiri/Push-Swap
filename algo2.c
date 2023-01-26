/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:25:16 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/25 13:15:52 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_idx_push(t_list **stack_a, t_list **stack_b, t_min *number)
{
	int	middle;

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

int	get_last_min(t_list *stack, t_min *number, int min, int a)
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

int	get_first_min(t_list *stack, t_min *number, int min, int a)
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

int	check_push(t_list **stack_a, t_list **stack_b,
				t_min *first_min, t_min *second_min)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (mouvments_num(first_min->idx, size)
		< mouvments_num(second_min->idx, size))
		check_idx_push(stack_a, stack_b, first_min);
	else
		check_idx_push(stack_a, stack_b, second_min);
	return (1);
}

int	check_range(t_list **stack_a, t_list **stack_b, int min, int a)
{
	int		indice;
	t_list	*stack;
	t_min	first_min;
	t_min	second_min;

	stack = *stack_a;
	indice = get_first_min(stack, &first_min, min, a);
	indice += get_last_min(*stack_a, &second_min, min, a);
	if (indice)
	{
		check_push(stack_a, stack_b, &first_min, &second_min);
		if ((*stack_b)->content > min + (a / 2))
			rotate(stack_b, 1);
		return (1);
	}
	return (0);
}
