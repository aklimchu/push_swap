/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:18:36 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/11 14:42:34 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algo_2(t_int **lst)
{
    if ((*lst)->content > (*lst)->next->content)
        swap_a(lst);
}

void    algo_3(t_int **lst)
{
    if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content \
        && (*lst)->content < (*lst)->next->next->content)
    {
        rotate_a(lst);
        swap_a(lst);
        r_rotate_a(lst);
    }
    if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content \
        && (*lst)->content < (*lst)->next->next->content)
        swap_a(lst);
    if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content \
        && (*lst)->content > (*lst)->next->next->content)
    {
        rotate_a(lst);
        rotate_a(lst);
    }
    if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content \
        && (*lst)->content > (*lst)->next->next->content)
        rotate_a(lst);
    if ((*lst)->content > (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content \
        && (*lst)->content > (*lst)->next->next->content)
    {
        swap_a(lst);
        r_rotate_a(lst);
    }
}

void    algo_4(t_int **lst1, t_int **lst2)
{
    int     i;
    
    push_b(lst1, lst2);
    algo_3(lst1);
    if ((*lst2)->content > (*lst1)->next->next->content)
    {
        push_a(lst1, lst2);
        rotate_a(lst1);
        return ;
    }
    i = 0;
    while ((*lst2)->content > (*lst1)->content)
    {
        rotate_a(lst1);
        i++;
    }
    push_a(lst1, lst2);
    while (i > 0)
    {
        r_rotate_a(lst1);
        i--;
    }
}

void    algo_5(t_int **lst1, t_int **lst2)
{
    int     i;
    
    push_b(lst1, lst2);
    push_b(lst1, lst2);
    if ((*lst2)->content < (*lst2)->next->content)
        swap_b(lst2);
    algo_3(lst1);
    if ((*lst2)->content > (*lst1)->next->next->content && \
        (*lst2)->next->content > (*lst1)->next->next->content)
    {
        push_a(lst1, lst2);
        push_a(lst1, lst2);
        rotate_a(lst1);
        rotate_a(lst1);
        return ;
    }
    if ((*lst2)->content < (*lst1)->content && \
        (*lst2)->next->content < (*lst1)->content)
    {
        push_a(lst1, lst2);
        push_a(lst1, lst2);
        return ;
    }
    i = 0;
    while ((*lst2)->content > (*lst1)->content)
    {
        rotate_a(lst1);
        i++;
    }
    push_a(lst1, lst2);
    while ((*lst2)->content < (*lst1)->next->next->next->content)
    {
        r_rotate_a(lst1);
        i--;
    }
    push_a(lst1, lst2);
    while (i > 0)
    {
        r_rotate_a(lst1);
        i--;
    }
}