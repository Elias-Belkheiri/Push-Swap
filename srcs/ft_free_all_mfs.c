/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_mfs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:09:26 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/27 12:21:23 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_all_mfs(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

int	ft_clear(char **arg, t_list **stack_a)
{
	ft_lstclear(stack_a);
	ft_free_all_mfs(arg);
	return (0);
}

int	ft_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstclear(stack_a);
	if (stack_b)
		ft_lstclear(stack_b);
	write(2, "ERROR\n", 6);
	exit (1);
}
