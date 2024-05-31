/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:39:51 by aklimchu          #+#    #+#             */
/*   Updated: 2024/05/31 13:16:23 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*whites(const char *str)
{
	while ((*str == 32) || (*str > 8 && *str < 14))
		str++;
	if (*str == 43 && *(str + 1) == 45)
		return (str);
	else if (*str == 43)
		str++;
	return (str);
}

long int	ft_atoi_long(const char *str)
{
	long int	res;
	int			neg;

	res = 0;
	neg = 1;
	str = whites(str);
	if (*str == 45)
	{
		neg = neg * (-1);
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}
