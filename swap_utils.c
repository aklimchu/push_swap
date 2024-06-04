/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:45:50 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/04 11:54:37 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void del_last(t_list **lst);

void swap_stack(t_list **lst)
{
    t_list  *temp1;
    t_list  *temp2;

    if (ft_lstsize(*lst) == 0 || ft_lstsize(*lst) == 1)
        return ;
    temp1 = *lst;
    temp2 = (*lst)->next;
    temp1->next = (*lst)->next->next;
    *lst = temp2;
    temp2->next = temp1;
    //ft_printf("sa\n");
}

int push_stack(t_list **lst1, t_list **lst2)
{
    t_list  *temp1;
    t_list  *temp2;
    t_list  *temp3;
    
    if (ft_lstsize(*lst2) == 0)
        return(-2);
    temp1 = ft_lstnew((*lst2)->content);
    if (temp1 == NULL)
        return(-1);
    ft_lstadd_front(lst1, temp1);
    temp2 = *lst2;
    temp3 = (*lst2)->next;
    free(temp2);
    //free(temp2->content);
    *lst2 = temp3;
    return(0);
}

void rotate_stack(t_list **lst)
{
    t_list  *temp1;
    t_list  *temp2;
    
    if (ft_lstsize(*lst) == 0)
        return ;
    temp1 = ft_lstnew((*lst)->content);
    ft_lstadd_back(lst, temp1);
    temp2 = (*lst)->next;
    free(*lst);
    *lst = temp2;
}

int r_rotate_stack(t_list **lst)
{
    t_list  *temp1;
    t_list  *temp2;
    
    if (ft_lstsize(*lst) == 0)
        return(-2);
    temp1 = ft_lstlast(*lst);
    temp2 = ft_lstnew(temp1->content);
    if (temp2 == NULL)
        return(-1);        
    ft_lstadd_front(lst, temp2);
    del_last(lst);
    return(0);
}

static void del_last(t_list **lst)
{
    t_list  *temp1;
    t_list  *temp2;
    
    temp1 = ft_lstlast(*lst);
    free(temp1);
    temp1 = NULL;
    temp2 = *lst;
    while (temp2->next->next)
        temp2 = temp2->next;
    temp2->next = NULL;    
}