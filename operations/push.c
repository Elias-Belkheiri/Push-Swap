/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:19:13 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/09 10:25:36 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **stack1, t_list **stack2)
{
	t_list *tmp;

	tmp = (*stack1)->next;
	ft_lstadd_front(stack2, *stack1);
	*stack1 = tmp;
}
