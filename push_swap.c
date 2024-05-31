/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:39:05 by aklimchu          #+#    #+#             */
/*   Updated: 2024/05/31 10:39:06 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int checkinput(int argc, char *argv[]);

void    push_swap(int argc, char *argv[])
{
    if (argc == 1)
        return ;
    if (checkinput(argc, argv) == 0)
        {
        ft_printf("Error\n");
        return ;
        }
}

static int checkinput(int argc, char *argv[])
{
    int     i;
    int     j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        if (argv[i][0] == '-')
            j++;
        while (argv[i][j] != '\0')
        {
            if (ft_isdigit(argv[i][j]) == 0)
                return(0);
            j++;
        }
        if (ft_atoi_long(argv[i]) > INT_MAX || ft_atoi_long(argv[i]) < INT_MIN)  // overflow for long int?
            return(0);
        i++;
        j = 0;
    }
    i = 1;
    j = 2;
    while (i < argc)
    {
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && i!=j)
                return(0);
            j++;
        }
        i++;
        j = 2;
    }
    return(1);
}