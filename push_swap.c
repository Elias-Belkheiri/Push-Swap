/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:39 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/27 12:23:49 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algos(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
		algo1(stack_a, 0);
	else if (ft_lstsize(*stack_a) <= 5)
		algo2(stack_a, stack_b);
	else
		algo3(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (argc < 2 || !argv)
		exit (0);
	stack_a = NULL;
	stack_b = NULL;
	i = -1;
	while (argv[++i + 1])
	{
		if (!check_and_push(argv[i + 1], &stack_a))
			ft_error(&stack_a, &stack_b);
	}
	if (is_sorted(stack_a))
		exit(EXIT_SUCCESS);
	algos(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
