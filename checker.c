/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:48:00 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/18 14:51:02 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valid_instruction(char *instruction, char *tmp)
{
	if (!ft_strncmp(instruction, "pa\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "pb\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "sa\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "sb\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "ss\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "ra\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "rb\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "rr\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "rra\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "rrb\n", ft_strlen(instruction))
		|| !ft_strncmp(instruction, "rrr\n", ft_strlen(instruction)))
		return ;
	write(1, "Error\n", 6);
	free(instruction);
	free(tmp);
	exit (1);
}

char	**read_from_si(void)
{
	char	*tmp;
	char	*tmp2;
	char	**instructions;

	tmp2 = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break;
		valid_instruction(tmp, tmp2);
		tmp2 = ft_strjoin(tmp2, tmp);
		free(tmp);
	}
	instructions = ft_split(tmp2, '\n');
	free(tmp2);
	return (instructions);
}

int	check_and_execute_instructions(char **instructions, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (instructions && instructions[i])
	{
		if (!ft_strncmp(instructions[i], "pa", ft_strlen(instructions[i])))
			push(stack_a, stack_b, 3);
		else if (!ft_strncmp(instructions[i], "pb", ft_strlen(instructions[i])))
			push(stack_b, stack_a, 3);
		else if (!ft_strncmp(instructions[i], "sa", ft_strlen(instructions[i])))
			swap(stack_a, 3);
		else if (!ft_strncmp(instructions[i], "sb", ft_strlen(instructions[i])))
			swap(stack_b, 3);
		else if (!ft_strncmp(instructions[i], "ss", ft_strlen(instructions[i])))
			ss(stack_a, stack_b, 3);
		else if (!ft_strncmp(instructions[i], "ra", ft_strlen(instructions[i])))
			rotate(stack_a, 3);
		else if (!ft_strncmp(instructions[i], "rb", ft_strlen(instructions[i])))
			rotate(stack_b, 3);
		else if (!ft_strncmp(instructions[i], "rr", ft_strlen(instructions[i])))
			rr(stack_a, stack_b, 3);
		else if (!ft_strncmp(instructions[i], "rra", ft_strlen(instructions[i])))
			rev_rotate(stack_a, 3);
		else if (!ft_strncmp(instructions[i], "rrb", ft_strlen(instructions[i])))
			rev_rotate(stack_b, 3);
		else if (!ft_strncmp(instructions[i], "rrr", ft_strlen(instructions[i])))
			rrr(stack_a, stack_b, 3);
		i++;
	}
	return (1);
}

void	check_stacks(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && !ft_lstsize(stack_b))
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	write(1, "KO\n", 3);
	exit(1);
}

int main(int argc, char *argv[])
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
		if (!ft_strlen(argv[i + 1]))
			return (ft_error());
    	if (!check_and_push(argv[i + 1], &stack_a))
        	return (ft_error());
	}
	instructions = read_from_si();
	print_list(stack_a);
	if (!check_and_execute_instructions(instructions, &stack_a, &stack_b))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	check_stacks(stack_a, stack_b);
}