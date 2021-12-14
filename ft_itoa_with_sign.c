/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_with_sign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:03:21 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/13 21:42:26 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	Allocates (with malloc(3)) and returns a string
*	representing the integer received as an argument.
*	Negative numbers must be handled.
*	RETURN VALUES
*	The string representing the integer. NULL if the allocation fails.
*/

#include "ft_printf.h"
#include "./libft/libft.h"

static int	new_str_len(int n)
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

static int	get_digit(int n, int length)
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

static int	new_n(int n, int length)
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

static char	*new_str_maker(char *new_str, int i, int n, int length)
{
	while (length != 0)
	{
		new_str[i] = (get_digit(n, length) + '0');
		n = new_n(n, length);
		i++;
		length--;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_itoa_with_sign(t_specs *specs, int n)
{
	char	*new_str;
	int		i;
	int		length;

	length = new_str_len(n);
	new_str = (char *)malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(new_str, "2147483648", 11);
		specs->sign = '-';
		return (new_str);
	}
	i = 0;
	if (n < 0)
	{
		specs->sign = '-';
		n = n * -1;
	}
	new_str = new_str_maker(new_str, i, n, length);
	return (new_str);
}
