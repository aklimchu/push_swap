/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrei <andrei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:13:22 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/21 15:14:30 by andrei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_last(t_int **lst);

void	rotate_a(t_int **lst1, t_int **lst2)
{
	t_int	*temp1;
	t_int	*temp2;

	if (ft_lstsize_int(*lst1) == 0)
		return ;
	temp1 = ft_lstnew_int((*lst1)->content, (*lst1)->simple);
	if (temp1 == NULL)
	{
		free_stacks(lst1, lst2);
		exit(0);
	}
	ft_lstadd_back_int(lst1, temp1);
	temp2 = (*lst1)->next;
	free(*lst1);
	*lst1 = temp2;
	ft_printf("ra\n");
}

void	rotate_b(t_int **lst1, t_int **lst2)
{
	t_int	*temp1;
	t_int	*temp2;

	if (ft_lstsize_int(*lst1) == 0)
		return ;
	temp1 = ft_lstnew_int((*lst1)->content, (*lst1)->simple);
	if (temp1 == NULL)
	{
		free_stacks(lst1, lst2);
		exit(0);
	}
	ft_lstadd_back_int(lst1, temp1);
	temp2 = (*lst1)->next;
	free(*lst1);
	*lst1 = temp2;
	ft_printf("rb\n");
}

void	r_rotate_a(t_int **lst1, t_int **lst2)
{
	t_int	*temp1;
	t_int	*temp2;

	if (ft_lstsize_int(*lst1) == 0)
		return ;
	temp1 = ft_lstlast_int(*lst1);
	temp2 = ft_lstnew_int(temp1->content, temp1->simple);
	if (temp2 == NULL)
	{
		free_stacks(lst1, lst2);
		exit(0);
	}
	ft_lstadd_front_int(lst1, temp2);
	del_last(lst1);
	ft_printf("rra\n");
}

void	r_rotate_b(t_int **lst1, t_int **lst2)
{
	t_int	*temp1;
	t_int	*temp2;

	if (ft_lstsize_int(*lst1) == 0)
		return ;
	temp1 = ft_lstlast_int(*lst1);
	temp2 = ft_lstnew_int(temp1->content, temp1->simple);
	if (temp2 == NULL)
	{
		free_stacks(lst1, lst2);
		exit(0);
	}
	ft_lstadd_front_int(lst1, temp2);
	del_last(lst1);
	ft_printf("rrb\n");
}

static void	del_last(t_int **lst)
{
	t_int	*temp1;
	t_int	*temp2;

	temp1 = ft_lstlast_int(*lst);
	temp2 = *lst;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1 = NULL;
	free(temp1);
}
