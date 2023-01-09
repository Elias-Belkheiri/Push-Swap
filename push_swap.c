/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:39 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/09 14:43:44 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_error()
{
	write(2, "ERROR\n", 6);
	return (1);
}

int main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;

	if (argc < 2 || !argv)
		exit (0);
	stack_a = stack_b = NULL;
	i = -1;
	while (argv[++i + 1])
	{
		if (!ft_strlen(argv[i + 1]))
			return (ft_error());
    	if (!check_and_push(argv[i + 1], &stack_a))
        	return (ft_error());
	}
	print_list(stack_a);
	printf("---------\n");
	rotate(&stack_a);
	print_list(stack_a);
}
