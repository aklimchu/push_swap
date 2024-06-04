/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:38:54 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/04 13:19:00 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//typedef struct s_list
//{
//	void			*content;
//	struct s_list	*next;
//}	t_list;

long int	ft_atoi_long(const char *str);
int         push_swap(int argc, char *argv[]);
int         swap_algo(int argc, char *argv[]);
void        swap_stack(t_list **lst);
int         push_stack(t_list **lst1, t_list **lst2);
void        rotate_stack(t_list **lst);
int         r_rotate_stack(t_list **lst);
t_list      *ft_lstnew_int(int content);

#endif /* PUSH_SWAP_H */