/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:55:11 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/10 00:56:05 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_sign(t_specs *specs, size_t i)
{
	if (specs->sign != '0')
	{
		specs->overall_length += write(1, &specs->sign, 1);
		i++;
	}
	return (i);
}

size_t	ft_put_rest(t_specs *specs, size_t len, size_t i, char char_to_put)
{
	if (specs->width > len)
	{
		if (specs->sign != '0' && specs->precision_dot == true
			&& specs->minus == false)
			len++;
		if (specs->sign != '0' && specs->zero == false && specs->minus == false)
			i++;
		while (i < (specs->width - len))
		{
			specs->overall_length += write(1, &char_to_put, 1);
			i++;
		}
	}
	return (i);
}

size_t	ft_put_sub_str(t_specs *specs, char *sub_str, size_t i)
{
	size_t	j;

	j = 0;
	while (sub_str[j])
	{
		specs->overall_length += write(1, &sub_str[j], 1);
		j++;
	}
	return (i + j);
}
