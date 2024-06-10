/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:18:36 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/10 16:00:46 by aklimchu         ###   ########.fr       */
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