// check That the Stack is not empty before popping.
// ---- check if the arguments are empty ----
// ---- check if the number contains only integers -----
// ----- check if the number is duplicated -----
// ---- check if an argument is < INT_MAX / > INT_MIN ----
// ---- check if there is only one string containing the numbers -----

/*

int is_duplicated(int num, t_list *stack_a)
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

int push_to_stack(char *arg, t_list  **stack_a)
{
    int num;

    num = ft_atoi(arg);
    if (is_duplicated)
        return (0);
    if (!ft_lstsize(*stack_a))
        *stack_a = ft_lstnew(num);
    else
        ft_lstadd_back(stack_a, ft_lstnew(num));
    return (1);
}

int only_digits(char *str)
{
    while (*str)
    {
        if (*str >= '0' && *str <= '9')
            str++;
        else
        return (0);
    }
	return (1);
}

int in_int_range(char *str)
{
    int n;

    n = ft_atoi(str);
    if (n < INT_MAX && n > INT_MIN)
        return (1);
    return (0);
}

int check_and_push(char *arg1, t_list  **stack_a)
{
    char    *arg;
    int     i;

    i = 0;
    arg = ft_split(arg1, ' ');
    if (!arg)
        return (0)
    while (arg[i])
    {
        if (only_digits(arg[i]) && in_int_range(arg[i]))
        {
            if (!push_to_stack(arg[i], stack_a));
            {
                free_all_mfs(arg);
                return (0)
            }
        }
        else
        return (0);
    }
    free_all_mfs(arg);
    return (1);
}

t_list  *stack_a;

stack_a = NULL;
if (!ft_strlen(argv[1]))
    return (ft_error);
i = -1;
while (argv[++i + 1])
{
    if (!check_and_push(argv[i + 1], &stack_a));
        return (ft_error);
}
*/