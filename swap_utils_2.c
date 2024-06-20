/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:13:22 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/12 14:56:38 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void del_last(t_int **lst);

int rotate_a(t_int **lst)
{
    t_int  *temp1;
    t_int  *temp2;
    
    if (ft_lstsize_int(*lst) == 0)
        return (-2);
    temp1 = ft_lstnew_int((*lst)->content, (*lst)->simple);
    if (temp1 == NULL)
        return(-1);    // freeing the stacks
    ft_lstadd_back_int(lst, temp1);
    temp2 = (*lst)->next;
    free(*lst);
    *lst = temp2;
    ft_printf("ra\n");
    return(0);
}

int rotate_b(t_int **lst)
{
    t_int  *temp1;
    t_int  *temp2;
    
    if (ft_lstsize_int(*lst) == 0)
        return (-2);
    temp1 = ft_lstnew_int((*lst)->content, (*lst)->simple);
    if (temp1 == NULL)
        return(-1);    // freeing the stacks
    ft_lstadd_back_int(lst, temp1);
    temp2 = (*lst)->next;
    free(*lst);
    *lst = temp2;
    ft_printf("rb\n");
    return(0);
}

int r_rotate_a(t_int **lst)
{
    t_int  *temp1;
    t_int  *temp2;
    
    if (ft_lstsize_int(*lst) == 0)
        return (-2);
    temp1 = ft_lstlast_int(*lst);
    temp2 = ft_lstnew_int(temp1->content, temp1->simple);
    if (temp2 == NULL)
        return(-1);    // freeing the stacks
    ft_lstadd_front_int(lst, temp2);
    del_last(lst);
    ft_printf("rra\n");
    return(0);
}

int r_rotate_b(t_int **lst)
{
    t_int  *temp1;
    t_int  *temp2;

    if (ft_lstsize_int(*lst) == 0)
        return (-2);
    temp1 = ft_lstlast_int(*lst);
    temp2 = ft_lstnew_int(temp1->content, temp1->simple);
    if (temp2 == NULL)
        return(-1);    // freeing the stacks
    ft_lstadd_front_int(lst, temp2);
    del_last(lst);
    ft_printf("rrb\n");
    return(0);
}

static void del_last(t_int **lst)
{
    t_int  *temp1;
    t_int  *temp2;
    
    temp1 = ft_lstlast_int(*lst);
    temp2 = *lst;
    while (temp2->next->next)
        temp2 = temp2->next;
    temp2->next = NULL;
    temp1 = NULL;
    free(temp1);
}