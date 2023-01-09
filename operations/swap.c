/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:33:49 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/09 10:25:15 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sa(t_list **stack)
{
	int	tmp;

	if ((*stack)->content < (*stack)->next->content ||
	!*stack)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	write (1, "sa\n", 3);
}

void	ss(t_list **stack1, t_list **stack2)
{
	sa(stack1);
	sa(stack2);
}