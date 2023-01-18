/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:43:15 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/17 13:46:09 by ebelkhei         ###   ########.fr       */
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

int	find_min(t_list *stack, int *idx)
{
	int	min;
	int	i;

	min = stack->content;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			*idx = i;
		}
		i++;
		stack = stack->next;
	}
	return (min);
}

void	algo2(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	idx;

	while (ft_lstsize(*stack_a) != 3)
	{
		min = find_min(*stack_a, &idx);
		if ((*stack_a)->content == min)
			push(stack_a, stack_b, 1);
		else if (idx > (ft_lstsize(*stack_a) / 2))
		{
			while ((*stack_a)->content != min)
				rev_rotate(stack_a, 0);
			push(stack_a, stack_b, 1);
		}
		else
		{
			while ((*stack_a)->content != min)
				rotate(stack_a, 0);
			push(stack_a, stack_b, 1);
		}
	}
	algo1(stack_a, 0);
	push(stack_b, stack_a, 0);
	push(stack_b, stack_a, 0);
}

// void algo2(t_list **stack_a, t_list **stack_b)
// {
// 	int	i;

// 	i = ft_lstsize(*stack_a) / 2;
// 	while (i--)
// 		push(stack_a, stack_b, 1);
// 	algo1(stack_a);
// 	algo1(stack_b);
// 	while (ft_lstsize(*stack_b))
// 	{
// 		push(stack_b, stack_a, 0);
// 		rotate(stack_a, 0);
// 	}
// }

int	ft_lstavg(t_list *stack)
{
	int	i;
	int	j;

	i = 0;
	j = ft_lstsize(stack);
	while (stack)
	{
		i += stack->content;
		stack = stack->next;
	}
	return (i / j);
}

// void algo3(t_list **stack_a, t_list **stack_b)
// {
// 	push(stack_a, stack_b, 0);
// 	push(stack_a, stack_b, 0);
// 	algo1(stack_a, 0);
// 	algo1(stack_b, 1);
// 	push(stack_b, stack_a, 1);
// 	algo1(stack_b, 1);
// 	// push(stack_b, stack_a, 1);
// 	algo1(stack_b, 1);
// }

// void algo(t_list **stack_a, t_list **stack_b)
// {
//     // while (ft_lstsize(*stack_a) != 1)
//     // {
//     //     if ((*stack_a)->content > (*stack_a)->next->content)
//     //         swap(stack_a, 0);
//     //     else
//     //         push(stack_a, stack_b, 0);
//     // }
//     // while (ft_lstsize(*stack_b))
//     // {
//     //     push(stack_b, stack_a, 1);
//     //     swap(stack_a, 0);
//     // }
//     (void)stack_b;

//     // int i = ft_lstsize(*stack_a);
//     // int j;
//     // while (i-- && !is_sorted(*stack_a))
//     // {
//     //     j = i;
//     //     while (j--)
//     //     {
//     //         swap(stack_a, 0);
//     //         rotate(stack_a, 0);
//     //     }
//     //     push(stack_a, stack_b, 0);
//     // }
//     // while (ft_lstsize(*stack_b))
//     // {
//     //     push(stack_b, stack_a, 1);
//     //     rotate(stack_a, 0);
//     // }
// }