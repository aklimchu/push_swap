/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:30 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/11 14:27:30 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_min(t_int *lst);

static int get_max(t_int *lst);

void    set_index(t_int **lst, int argc)
{
    int     num_min;
    int     num_max;
    t_int   *temp;

    num_min = get_min(*lst);
    num_max = get_max(*lst);
    temp = *lst;
    while (*lst)
    {
        (*lst)->index = 0 + ((((*lst)->content - num_min) * (argc - 2 - 0)) / (num_max - num_min));
        *lst = (*lst)->next;
    }
    *lst = temp;
}

static int get_min(t_int *lst)
{
    int     num_min;

    num_min = lst->content;
    while (lst->next)
    {
        if (lst->content > lst->next->content)
            num_min = lst->next->content;
        lst = lst->next;
    }
    return(num_min);
}

static int get_max(t_int *lst)
{
    int     num_max;

    num_max = lst->content;
    while (lst->next)
    {
        if (lst->content < lst->next->content)
            num_max = lst->next->content;
        lst = lst->next;
    }
    return(num_max);
}