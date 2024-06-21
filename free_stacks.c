/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrei <andrei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:45:50 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/21 15:29:54 by andrei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"  // check ALL 42 headers in EVERY file!!!

void free_stacks(t_int **lst1, t_int **lst2)
{
    t_int   *temp;

    while (*lst1)
    {
        temp = (*lst1)->next;
        free(*lst1);
        *lst1 = temp;
    }
    free(*lst1);    // do we need?
    while (*lst2)
    {
        temp = (*lst2)->next;
        free(*lst2);
        *lst2 = temp;
    }
    free(*lst2);    // do we need?
}