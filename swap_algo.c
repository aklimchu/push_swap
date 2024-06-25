/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrei <andrei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:38:27 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/21 15:40:25 by andrei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_options(int argc, t_int **lst1, t_int **lst2);

static void	stacks_fill(int argc, char *argv[], t_int **lst1, t_int **lst2);

void	swap_algo(int argc, char *argv[])
{
	t_int	**stack_a;
	t_int	**stack_b;

	stack_a = (t_int **)malloc((argc - 1) * sizeof(t_int));
	if (stack_a == NULL)
	{
		//free_stacks(&stack_a, &stack_b);
		exit(0);
	}
	stack_b = (t_int **)malloc((argc - 1) * sizeof(t_int));
	if (stack_b == NULL)
	{
		free(stack_a);
		//free_stacks(&stack_a, &stack_b); //???
		exit(0);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	stacks_fill(argc, argv, stack_a, stack_b);
	algo_options(argc, stack_a, stack_b);
	free(stack_a);	//???
	stack_a = NULL;	//???
	free(stack_b);	//???
	stack_a = NULL;	//???
}

static void	stacks_fill(int argc, char *argv[], t_int **lst1, t_int **lst2)
{
	int		i;
	int		new_num;
	t_int	*new;

	/*if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}*/
	i = 1;
	while (i < argc)
	{
		new_num = ft_atoi(argv[i]);
		new = ft_lstnew_int(new_num, 0);
		if (new == NULL)
		{
			free_stacks(lst1, lst2);
			exit(0);
		}
		ft_lstadd_back_int(lst1, new);
		i++;
	}
}

static void	algo_options(int argc, t_int **lst1, t_int **lst2)
{
	if (a_is_sorted(*lst1) == 0)
	{
		free_stacks(lst1, lst2);
		exit(0);
	}
	set_simple(lst1);
	if (argc == 3)
		algo_2(lst1);
	if (argc == 4)
		algo_3(lst1, lst2);
	if (argc == 5)
		algo_4(lst1, lst2);
	if (argc == 6)
		algo_5(lst1, lst2);
	if (argc >= 7)
		algo_large(lst1, lst2);
	/*temp = stack_a;
	ft_printf("Stack a - simplees\n");
	while (temp)
	{
		ft_printf("%d\n", temp->simple);
		temp = temp->next;
	}
	ft_printf("Stack a\n");
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\nStack b\n");
	while (stack_b)
	{
		ft_printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
	}*/
	//free_stacks(lst1, lst2);
}
