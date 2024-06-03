/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:38:54 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/03 14:54:16 by aklimchu         ###   ########.fr       */
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
void        push_swap(int argc, char *argv[]);
void        swap_algo(int argc, char *argv[]);
void        swap_stack(t_list **lst);
void        push_stack(t_list **lst1, t_list **lst2);
void        rotate_stack(t_list **lst);
void        r_rotate_stack(t_list **lst);

#endif /* PUSH_SWAP_H */