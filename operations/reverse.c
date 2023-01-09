/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:33:53 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/09 14:38:13 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
}