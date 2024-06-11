/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:38:27 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/11 14:32:14 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_algo(int argc, char  *argv[])
{
    t_int   *stack_a;
    t_int   *stack_b;
    t_int   *new;
    int     i;
    int     new_num;

    stack_a = (t_int *)malloc((argc - 1) * sizeof(t_int));   // sizeof (t_int *)?
    stack_b = (t_int *)malloc((argc - 1) * sizeof(t_int));
    if (stack_a == NULL || stack_b == NULL)     // checking if some memory was allocated and freeing it
        exit(0);        
    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    while (i < argc)
    {
        new_num = ft_atoi(argv[i]);
        new = ft_lstnew_int(new_num);
        ft_lstadd_back_int(&stack_a, new);
        i++;
    }
    if (a_is_sorted(stack_a) == 0)
        exit(0);    //  freeing the memory
    if (argc == 3)
        algo_2(&stack_a);
    if (argc == 4)
        algo_3(&stack_a);
    if (argc == 5)
        algo_4(&stack_a, &stack_b);
    if (argc == 6)
        algo_5(&stack_a, &stack_b);
    /*set_index(&stack_a, argc);
    ft_printf("Stack a - indexes\n");
    while (stack_a)
    {
        ft_printf("%d\n", stack_a->index);
        stack_a = stack_a->next;
    }*/
    //push_b(&stack_b, &stack_a);
    //swap_a(&stack_a);
    /*ft_printf("Stack a\n");
    while (stack_a)
    {
        ft_printf("%d\n", stack_a->content);
        stack_a = stack_a->next;
    }
    ft_printf("\nStack b\n");
    while (stack_b)
    {
        ft_printf("%d\n", stack_b->content);
        stack_b = stack_b->next;
    }*/
    free(stack_a);
    free(stack_b);
}