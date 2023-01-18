/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:51:01 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/17 12:08:22 by ebelkhei         ###   ########.fr       */
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