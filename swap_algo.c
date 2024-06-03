/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:38:27 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/03 16:11:42 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_algo(int argc, char  *argv[])
{
    t_list *stack_a;
    t_list *stack_b;
    t_list *new;
    int     i;

    stack_a = (t_list *)malloc(argc * sizeof(t_list));   // sizeof (t_list *)?
    stack_b = (t_list *)malloc(argc * sizeof(t_list));
    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    while (i < argc)
    {
        new = ft_lstnew(argv[i]);
        ft_lstadd_back(&stack_a, new);
        i++;
    }
    //swap_stack(&stack_a);
    //push_stack(&stack_b, &stack_a);
    r_rotate_stack(&stack_a);
    i = 1;
    ft_printf("Stack a\n");
    while (stack_a)
    {
        ft_printf("%s\n", (char *)stack_a->content);
        stack_a = stack_a->next;
    }
    ft_printf("\nStack b\n");
    while (stack_b)
    {
        ft_printf("%s\n", (char *)stack_b->content);
        stack_b = stack_b->next;
    }
}