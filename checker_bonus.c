/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:48:00 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/26 15:18:02 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "ERROR\n", 6);
	return (1);
}

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
	write(2, "Error\n", 6);
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
	while (instructions && *instructions)
	{
		if (!ft_strncmp(*instructions, "pa", ft_strlen(*instructions)))
			push(stack_b, stack_a, 3);
		else if (!ft_strncmp(*instructions, "pb", ft_strlen(*instructions)))
			push(stack_a, stack_b, 3);
		else if (!ft_strncmp(*instructions, "sa", ft_strlen(*instructions)))
			swap(stack_a, 3);
		else if (!ft_strncmp(*instructions, "sb", ft_strlen(*instructions)))
			swap(stack_b, 3);
		else if (!ft_strncmp(*instructions, "ss", ft_strlen(*instructions)))
			ss(stack_a, stack_b, 3);
		else if (!ft_strncmp(*instructions, "ra", ft_strlen(*instructions)))
			rotate(stack_a, 3);
		else if (!ft_strncmp(*instructions, "rb", ft_strlen(*instructions)))
			rotate(stack_b, 3);
		else if (!ft_strncmp(*instructions, "rr", ft_strlen(*instructions)))
			rr(stack_a, stack_b, 3);
		else if (!ft_strncmp(*instructions, "rra", ft_strlen(*instructions)))
			rev_rotate(stack_a, 3);
		else if (!ft_strncmp(*instructions, "rrb", ft_strlen(*instructions)))
			rev_rotate(stack_b, 3);
		else if (!ft_strncmp(*instructions, "rrr", ft_strlen(*instructions)))
			rrr(stack_a, stack_b, 3);
		else
			return (0);
		instructions++;
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
	if (!check_and_execute_instructions(instructions, &stack_a, &stack_b))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	 check_stacks(stack_a, stack_b);
}
