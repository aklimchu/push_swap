/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:38:54 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/10 15:20:27 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_int
{
	int 			content;
	//int				index;
	//int				sequence;
	struct s_int	*next;
}	t_int;

long int	ft_atoi_long(const char *str);
int         push_swap(int argc, char *argv[]);
void         swap_algo(int argc, char *argv[]);
void        swap_a(t_int **lst);
void        swap_b(t_int **lst);
void		push_a(t_int **lst1, t_int **lst2);
void		push_b(t_int **lst1, t_int **lst2);
int	        rotate_a(t_int **lst);
int        rotate_b(t_int **lst);
int	        r_rotate_a(t_int **lst);
int	        r_rotate_b(t_int **lst);
t_int      *ft_lstnew_int(int content);
void	    ft_lstadd_front_int(t_int **lst, t_int *new);
t_int	    *ft_lstlast_int(t_int *lst);
int         ft_lstsize_int(t_int *lst);
void	    ft_lstadd_back_int(t_int **lst, t_int *new);
void    	algo_2(t_int **lst);
void		algo_3(t_int **lst);


#endif /* PUSH_SWAP_H */