/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:39 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/18 14:44:52 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;

	if (argc < 2 || !argv)
		exit (0);
	stack_a = NULL;
	stack_b = NULL;
	i = -1;
	while (argv[++i + 1])
	{
		if (!ft_strlen(argv[i + 1]))
			return (ft_error());
    	if (!check_and_push(argv[i + 1], &stack_a))
        	return (ft_error());
	}
	if (is_sorted(stack_a))
		exit(EXIT_SUCCESS);
	algo3(&stack_a, &stack_b);
	// algo1(&stack_a, 0);
	// algo3(&stack_a, &stack_b);
	// printf("------------\n");
	// print_list(stack_a);
	// printf("------------\n");
	// print_list(stack_b);
	// if (is_sorted(stack_a))
	// 	printf("ok\n");
}
