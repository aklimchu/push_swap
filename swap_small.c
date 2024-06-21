/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrei <andrei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:18:36 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/21 15:28:16 by andrei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void algo_3_case(t_int **lst1, t_int **lst2);

void    algo_2(t_int **lst)
{
    if ((*lst)->content > (*lst)->next->content)
        swap_a(lst);
}

void    algo_3(t_int **lst1, t_int **lst2)
{
    if (a_is_sorted(*lst1) == 0)
        return ;
    if ((*lst1)->content < (*lst1)->next->content && (*lst1)->next->content > (*lst1)->next->next->content \
        && (*lst1)->content < (*lst1)->next->next->content)
        algo_3_case(lst1, lst2);
    if ((*lst1)->content > (*lst1)->next->content && (*lst1)->next->content < (*lst1)->next->next->content \
        && (*lst1)->content < (*lst1)->next->next->content)
        swap_a(lst1);
    if ((*lst1)->content < (*lst1)->next->content && (*lst1)->next->content > (*lst1)->next->next->content \
        && (*lst1)->content > (*lst1)->next->next->content)
    {
        rotate_a(lst1, lst2);
        rotate_a(lst1, lst2);
    }
    if ((*lst1)->content > (*lst1)->next->content && (*lst1)->next->content < (*lst1)->next->next->content \
        && (*lst1)->content > (*lst1)->next->next->content)
        rotate_a(lst1, lst2);
    if ((*lst1)->content > (*lst1)->next->content && (*lst1)->next->content > (*lst1)->next->next->content \
        && (*lst1)->content > (*lst1)->next->next->content)
    {
        swap_a(lst1);
        r_rotate_a(lst1, lst2);
    }
}

void    algo_4(t_int **lst1, t_int **lst2)
{
    int     i;
    
    push_b(lst1, lst2);
    algo_3(lst1, lst2);
    if ((*lst2)->content > (*lst1)->next->next->content)
    {
        push_a(lst1, lst2);
        rotate_a(lst1, lst2);
        return ;
    }
    i = 0;
    while ((*lst2)->content > (*lst1)->content)
    {
        rotate_a(lst1, lst2);
        i++;
    }
    push_a(lst1, lst2);
    while (i > 0)
    {
        r_rotate_a(lst1, lst2);
        i--;
    }
}

static void algo_3_case(t_int **lst1, t_int **lst2)
{
    rotate_a(lst1, lst2);
    swap_a(lst1);
    r_rotate_a(lst1, lst2);
}