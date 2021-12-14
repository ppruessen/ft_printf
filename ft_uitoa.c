/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:03:21 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/14 13:08:23 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	Allocates (with malloc(3)) and returns a string
*	representing the unsigned integer received as an argument.
*	Negative numbers must be handled.
*	RETURN VALUES
*	The string representing the integer. NULL if the allocation fails.
*/

#include "ft_printf.h"
#include "libft/libft.h"

static int	new_ustr_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	get_udigit(unsigned int n, int length)
{
	int	power;
	int	result;

	power = 1;
	while (length > 1)
	{
		power = power * 10;
		length--;
	}
	result = n / power;
	return (result);
}

static int	new_un(unsigned int n, int length)
{
	int	power;
	int	result;
	int	temp;

	power = 1;
	while (length > 1)
	{
		power = power * 10;
		length--;
	}
	temp = n / power;
	result = n - temp * power;
	return (result);
}

static char	*new_ustr_maker(char *new_str, int i, unsigned int n, int length)
{
	while (length != 0)
	{
		new_str[i] = (get_udigit(n, length) + '0');
		n = new_un(n, length);
		i++;
		length--;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_uitoa(unsigned int n)
{
	char	*new_str;
	int		i;
	int		length;

	length = new_ustr_len(n);
	new_str = (char *)malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	new_str = new_ustr_maker(new_str, i, n, length);
	return (new_str);
}
