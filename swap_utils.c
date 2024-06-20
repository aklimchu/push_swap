/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:45:50 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/12 14:59:07 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_int **lst)
{
    t_int  *temp1;
    t_int  *temp2;

    if (ft_lstsize_int(*lst) == 0 || ft_lstsize_int(*lst) == 1)
        return ;
    temp1 = *lst;
    temp2 = (*lst)->next;
    temp1->next = (*lst)->next->next;
    *lst = temp2;
    temp2->next = temp1;
    ft_printf("sa\n");
}

void swap_b(t_int **lst)
{
    t_int  *temp1;
    t_int  *temp2;

    if (ft_lstsize_int(*lst) == 0 || ft_lstsize_int(*lst) == 1)
        return ;
    temp1 = *lst;
    temp2 = (*lst)->next;
    temp1->next = (*lst)->next->next;
    *lst = temp2;
    temp2->next = temp1;
    ft_printf("sb\n");
}

void push_a(t_int **lst1, t_int **lst2)
{
    t_int  *temp1;
    t_int  *temp2;
    t_int  *temp3;
    
    if (ft_lstsize_int(*lst2) == 0)
        return ;
    temp1 = ft_lstnew_int((*lst2)->content, (*lst2)->simple);
    if (temp1 == NULL)
        exit(0);    // freeing the stacks before exiting
    ft_lstadd_front_int(lst1, temp1);
    temp2 = *lst2;
    temp3 = (*lst2)->next;
    free(temp2);
    //free(temp2->content);
    *lst2 = temp3;
    ft_printf("pa\n");
}

void push_b(t_int **lst1, t_int **lst2)
{
    t_int  *temp1;
    t_int  *temp2;
    t_int  *temp3;
    
    if (ft_lstsize_int(*lst1) == 0)
        return ;
    temp1 = ft_lstnew_int((*lst1)->content, (*lst1)->simple);
    if (temp1 == NULL)
        exit(0);    // freeing the stacks before exiting
    ft_lstadd_front_int(lst2, temp1);
    temp2 = *lst1;
    temp3 = (*lst1)->next;
    free(temp2);
    //free(temp2->content);
    *lst1 = temp3;
    ft_printf("pb\n");
}

int a_is_sorted(t_int *lst)
{
    while (lst->next)
    {
        if (lst->content > lst->next->content)
            return(-1);
        lst = lst->next;
    }
    return(0);
}