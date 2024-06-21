/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrei <andrei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:02:40 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/21 15:44:25 by andrei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int b_to_a_first_number(t_int **lst1, t_int **lst2, int i);

static int b_to_a_second_number(t_int **lst1, t_int **lst2, int i);

static int  b_to_a_second_number_cases(t_int **lst1, t_int **lst2, int i);

void    algo_5(t_int **lst1, t_int **lst2)
{
    int     i;
    
    push_b(lst1, lst2);
    push_b(lst1, lst2);
    if ((*lst2)->content < (*lst2)->next->content)
        swap_b(lst2);
    algo_3(lst1, lst2);
    i = 0;   
    i = b_to_a_first_number(lst1, lst2, i);
    i = b_to_a_second_number(lst1, lst2, i);
    if (*lst2)
        push_a(lst1, lst2);
    while (i > 0)
    {
        r_rotate_a(lst1, lst2);
        i--;
    }
    while (i < 0)
    {
        rotate_a(lst1, lst2);
        i++;
    }
}

static int b_to_a_first_number(t_int **lst1, t_int **lst2, int  i)
{
    if ((*lst2)->content > (*lst1)->next->next->content)
    {
        push_a(lst1, lst2);
        i--;
    }
    else
    {
        while ((*lst2)->content > (*lst1)->content)
        {
            rotate_a(lst1, lst2);
            i++;
        }
        push_a(lst1, lst2);
    }
    return(i);
}

static int b_to_a_second_number(t_int **lst1, t_int **lst2, int i)
{
    if ((*lst2)->content < get_min(*lst1))
    {
        while (i > 0)
        {
            r_rotate_a(lst1, lst2);
            i--;
        }
        while (i < 0)
        {
            rotate_a(lst1, lst2);
            i++;
        }
        push_a(lst1, lst2);
    }
    if ((*lst2) && (*lst2)->content < (*lst1)->content && \
            (*lst2)->content > (*lst1)->next->next->next->content)
    {
        push_a(lst1, lst2);
        if (i == -1)
            i--;
    }
    i = b_to_a_second_number_cases(lst1, lst2, i);
    return(i);
}

static int  b_to_a_second_number_cases(t_int **lst1, t_int **lst2, int i)
{
    if ((*lst2) && (*lst1)->next->next->content == get_min(*lst1))
    {
        while ((*lst2)->content < (*lst1)->next->next->next->content || \
            (*lst2)->content > (*lst1)->content)
        {
            r_rotate_a(lst1, lst2);
            i--;
        }
        push_a(lst1, lst2);
    }
    if ((*lst2) && (*lst2)->content < (*lst1)->next->next->next->content && \
            (*lst2)->content > (*lst1)->next->next->content)
    {
        r_rotate_a(lst1, lst2);
        i = i - 2;
        push_a(lst1, lst2);
    }
    while ((*lst2) && ((*lst2)->content < (*lst1)->next->next->next->content || \
            (*lst2)->content > (*lst1)->content))
    {
        rotate_a(lst1, lst2);
        i++;
    }
    return(i);
}