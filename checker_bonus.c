/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:48:00 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/27 15:42:20 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**instructions;	
	int		i;

	if (argc < 2)
		exit (0);
	stack_a = NULL;
	stack_b = NULL;
	i = -1;
	while (argv[++i + 1])
	{
		if (!check_and_push(argv[i + 1], &stack_a))
			ft_error(&stack_a, &stack_a);
	}
	instructions = read_from_si();
	if (!check_and_execute_instructions(instructions, &stack_a, &stack_b))
		ft_error(&stack_a, &stack_a);
	check_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
