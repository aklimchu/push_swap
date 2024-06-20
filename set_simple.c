/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:30 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/12 14:49:45 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_simple(t_int **lst)
{
    t_int   *temp1;
    t_int   *temp2;
    int     count_smaller;
    
    temp1 = *lst;
    while (temp1)
    {
        temp2 = *lst;
        count_smaller = 0;
        while (temp2)
        {
            if (temp1->content > temp2->content)
                 count_smaller++;
            temp2 = temp2->next;
        }
        temp1->simple = count_smaller;
        temp1 = temp1->next;
    }
    
}

int get_min(t_int *lst)
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