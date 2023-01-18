// check That the Stack is not empty before popping.
// ---- check if the arguments are empty ----
// ---- check if the number contains only integers -----
// ----- check if the number is duplicated -----
// ---- check if an argument is < INT_MAX / > INT_MIN ----
// ---- check if there is only one string containing the numbers -----

/*

void getMinMax(t_list *stack, int *min, int *max)
{
    *min = stack->content;
    *max = stack->content;
    while (stack)
    {
        if (stack->content < min)
            min = stack->content;
        if (stack->content > max)
            max = stack->content;
        stack = stack->next;
    }
}

int	find_min_2(t_list *stack, t_min *number)
{
	int	i;

	number->num = stack->content;
	i = 0;
	while (stack)
	{
		if (stack->content < min + 12)
		{
			number->num = stack->content;
			number->idx = i;
			return (1);
		}
		i++;
		stack = stack->next;
	}
	return (0);
}

int mouvments_num(int idx, int size)
{
	int middle;

	middle = size / 2;
	if (idx > middle)
		return (idx);
	return (size - idx);
}

void	check_idx_push(t_list **stack_a, t_list **stack_b, t_min *number, int size)
{
	int middle;

	middle = size / 2;
	if (number->idx < middle)
	{
		while ((*stack_a)->content != number->num)
			rotate(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->content != number->num)
			rev_rotate(stack_a, 0);
	}
	push(stack_a, 0);
}

int	check_push(t_list **stack_a, t_list **stack_b, t_min *firstMin, t_min *secondMin)
{
	int	size;

	size = ft_lstsize(*stack_a)
	if (mouvments_num(firstMin->idx, size) < mouvments_num(secondMin->idx, size))
		check_idx_push(stack_a, stack_b, firstMin, size);
	else
		check_idx_push(stack_a, stack_b, secondMin, size);
	return (1);
}

int    check_range(t_list **stack_a, t_list **stack_b, int min)
{
	int		i;
	int		indice;
    t_list *stack;
	t_min	firstMin;
	t_min	secondMin;

	stack = *stack_a;
	indice = find_min_2(stack, &firstMin);
	find_min_2(stack, &secondMin);
	i = 0;
	while (stack)
	{
		if (stack->content < min + 12)
		{
			secondMin.num = stack->content;
			secondMin.idx = i;
			indice++;
		}
		stack = stack->content;
	}
	if (indice)
		return (check_Push(stack_a, stack_b, &firstMin, &secondMin));
	return (0);
}

void    algo3(t_list **stack_a, t_list **stack_b)
{
    int min;
    int max;
    int p;

    getMinMax(*stack_a, &min, &max);
    while (ft_lstsize(*stack_a))
    {
        p = check_range(stack_a, stack_b, min);
        while (p)
            check_range(stack_a, stack_b, min);
        min += 12;
    }
}
*/