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

int    push_swap(int argc, char *argv[])
{
    int     i;

    if (argc < 3)
        return(-1);
    if (checkinput(argc, argv) == 0)
        return(ft_printf("Error\n"));
    i = 1;
    if (swap_algo(argc, argv) == -1)            // freeing memory, checking for leaks?
        return (ft_printf("Error during memory allocation"));
    return(0);
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

/*t_list	*ft_lstnew_int(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new == NULL)
		return ((void *) 0);
	new->content = content;
	new->next = NULL;
	return (new);
}*/