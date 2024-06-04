/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:38:27 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/04 14:33:08 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int swap_actions (t_list **stack_a, t_list **stack_b, int argc);*/

int    swap_algo(int argc, char  *argv[])
{
    t_list *stack_a;
    t_list *stack_b;
    t_list *new;
    int     i;

    stack_a = (t_list *)malloc((argc - 1) * sizeof(t_list));   // sizeof (t_list *)?
    stack_b = (t_list *)malloc((argc - 1) * sizeof(t_list));
    if (stack_a == NULL || stack_b == NULL)
        return(-1);        
    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    while (i < argc)
    {
        new = ft_lstnew(argv[i]);
        ft_lstadd_back(&stack_a, new);
        i++;
    }
    /*if (swap_actions(&stack_a, &stack_b, argc) == -1)
        return(-1);             // freeing stack_a, stack_b, anything else?*/
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
    free(stack_a);
    free(stack_b);
    return(0);
}

/*static int swap_actions (t_list **stack_a, t_list **stack_b, int argc)
{
    int     count;
    int     dist;
    t_list  *temp1;
    t_list  *temp2;
    
    count = 0;
    dist = 0;
    temp1 = *stack_a;
    temp2 = *stack_b;
    //ft_printf("%d\n\n", ft_atoi(temp1->content));
    while (count < argc)
    {
        if (temp1->next)
        {
            if (ft_atoi(temp1->content) > ft_atoi(temp1->next->content))
                rotate_stack(&temp1);
            else
            {
                push_stack(&temp2, &temp1);
                if (temp2->next)
                {
                    if (ft_atoi(temp2->content) < ft_atoi(temp2->next->content))
                        rotate_stack(&temp2);
                }
            }
            //temp1 = temp1->next;
        }
        count++;
    }
    //while (temp2)
    //    push_stack(&temp1, &temp2);
    //swap_stack(stack_a);
    //push_stack(stack_b, stack_a);
    //r_rotate_stack(stack_a);
    return(0);
}*/