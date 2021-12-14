/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:49:14 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/14 16:47:23 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"libft/libft.h"

static int	new_hex_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*new_hex_maker(char *new_str, unsigned int n, int length)
{
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	i = length;
	while (length != 0)
	{
		length--;
		new_str[length] = base[n % 16];
		n = n / 16;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_uitohex(unsigned int n)
{
	char	*new_str;
	int		length;

	length = new_hex_len(n);
	new_str = (char *)malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (NULL);
	new_str = new_hex_maker(new_str, n, length);
	return (new_str);
}
