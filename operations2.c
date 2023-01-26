/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:27:37 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/25 14:22:53 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack1, t_list **stack2, int a)
{
	swap(stack1, a);
	swap(stack2, a);
}

void	rr(t_list **stack1, t_list **stack2, int a)
{
	rotate(stack1, a);
	rotate(stack2, a);
}

void	rrr(t_list **stack1, t_list **stack2, int a)
{
	rev_rotate(stack1, a);
	rev_rotate(stack2, a);
}
