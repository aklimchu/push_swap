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

static int checknum(char *str);

int    push_swap(int argc, char *argv[])
{
    // Should the program be able to take 1 string as an argument?
    //if (argc < 2)
    //    exit(0);
    //if (argc == 2)

    if (checkinput(argc, argv) == 0)
    {
        write(2, "Error\n", 6);
        exit(0);
    }
    if (argc < 3)
        exit(0);
    swap_algo(argc, argv);
    //if (swap_algo(argc, argv) == -1)            // freeing memory, checking for leaks?
    //    return (ft_printf("Error during memory allocation"));
    return(0);
}

static int checkinput(int argc, char *argv[])
{
    int     i;
    int     j;

    i = 1;
    while (i < argc)
    {
        if (checknum(argv[i]) == 0)
            return(0);
        i++;
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

static int checknum(char *str)
{
    int     j;

    j = 0;    
    if (str[0] == '-')
        j++;
    if (str[j] == '\0')
        return(0);
    while (str[j] != '\0')
    {
        if (ft_isdigit(str[j]) == 0)
            return(0);
        j++;
    }
    if (ft_atoi_long(str) > INT_MAX || ft_atoi_long(str) < INT_MIN)  // overflow for long int?
        return(0);
    return(1);
}