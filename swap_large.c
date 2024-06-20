/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:38:27 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/20 14:32:08 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        algo_large(t_int **lst1, t_int **lst2)
{
    int     num_max;
    int     bits_count;
    int     i;
    int     j;

    //bits_count = 0;
    *lst2 = NULL; //delete
    num_max = ft_lstsize_int(*lst1) - 1;
    //ft_printf("Num max %d\n", num_max);
    while ((num_max >> bits_count) != 0)
        bits_count++;
    //ft_printf("Bits count %d\n", bits_count);
    while (i < bits_count)
    {
        while (j < num_max +1)
        {
            if ((((*lst1)->simple >> i)&1) == 1)
                rotate_a(lst1);
            else
                push_b(lst1, lst2);
            ++j;
        }
        j = 0;
        while (ft_lstsize_int(*lst2))
            push_a(lst1, lst2);
        ++i;
    }
}