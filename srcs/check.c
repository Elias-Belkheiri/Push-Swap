/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:23:20 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/26 16:21:32 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_duplicated(int num, t_list *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->content == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	push_to_stack(char *arg, t_list **stack_a)
{
	int	num;

	num = ft_atoi(arg);
	if (is_duplicated(num, *stack_a))
		return (0);
	if (!ft_lstsize(*stack_a))
		*stack_a = ft_lstnew(num);
	else
		ft_lstadd_back(stack_a, ft_lstnew(num));
	return (1);
}

int	only_digits(char *str)
{
	if ((*str == '+' || *str == '-'))
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

int	in_int_range(char *str)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i])
		i++;
	if (i > 11)
		return (0);
	n = ft_atoi(str);
	if (n <= INT_MAX && n >= INT_MIN)
		return (1);
	return (0);
}

int	check_and_push(char *arg1, t_list **stack_a)
{
	char	**arg;
	int		i;

	i = -1;
	arg = ft_split(arg1, ' ');
	if (!arg || !*arg || !ft_strlen(arg1))
		return (0);
	while (arg[++i])
	{
		if (only_digits(arg[i]) && in_int_range(arg[i]))
		{
			if (!push_to_stack(arg[i], stack_a))
				return (ft_clear(arg, stack_a));
		}
		else
			return (ft_clear(arg, stack_a));
	}
	ft_free_all_mfs(arg);
	return (1);
}
