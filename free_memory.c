/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:45:50 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/26 14:50:16 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_int **lst1, t_int **lst2)
{
	t_int	*temp;

	while (*lst1)
	{
		temp = *lst1;
		*lst1 = (*lst1)->next;
		free(temp);
	}
	free(lst1);
	lst1 = NULL;
	while (*lst2)
	{
		temp = *lst2;
		*lst2 = (*lst2)->next;
		free(temp);
	}
	free(lst2);
	lst2 = NULL;
}

void	free_arr(char *arr[])
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
