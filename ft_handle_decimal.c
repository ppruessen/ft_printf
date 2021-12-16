/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:09:23 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/16 01:58:47 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_sign(t_specs *specs)
{
	if (specs->sub_str[0] == '0' && specs->sign == '0')
		return ;
	if (specs->sign != '0')
		specs->overall_length += write(1, &specs->sign, 1);
	return ;
}

static void	ft_put_sub_str(t_specs *specs)
{
	size_t	i;

	i = 0;
	if (specs->sub_str[i] == '0' && specs->precision_dot == 1
		&& specs->precision == 0)
		return ;
	while (specs->sub_str[i] != '\0')
	{
		specs->overall_length += write(1, &specs->sub_str[i], 1);
		i++;
	}
	return ;
}

static void	ft_put_width(t_specs *specs)
{
	int		length;
	size_t	i;
	char	to_put;

	length = specs->width;
	if (specs->zero == 1 && specs->precision_dot == 0)
		to_put = '0';
	else
		to_put = ' ';
	if (specs->width < specs->precision + 1)
		return ;
	else if (specs->precision > ft_strlen(specs->sub_str))
		length = specs->width - specs->precision;
	else
		length -= ft_strlen(specs->sub_str);
	if (specs->sign != '0')
		length--;
	i = 0;
	if (specs->sub_str[i] == '0' && specs->precision_dot == 1)
		length++;
	if (length > 0)
		while ((int)i < length)
			i = ft_put_char(specs, i, to_put);
}

static void	ft_put_precision(t_specs *specs)
{
	int		length;
	size_t	i;

	length = specs->precision - (int)ft_strlen(specs->sub_str);
	i = 0;
	if (length > 0)
		while ((int)i < length)
			i = ft_put_char(specs, i, '0');
}

void	ft_handle_decimal(t_specs *specs)
{
	specs->sub_str = ft_itoa_with_sign(specs, va_arg(specs->args, int));
	if (specs->zero == 1 && specs->precision_dot == 0)
	{
		ft_put_sign(specs);
		ft_put_width(specs);
		ft_put_precision(specs);
		ft_put_sub_str(specs);
	}
	else if (specs->minus == 1)
	{
		ft_put_sign(specs);
		ft_put_precision(specs);
		ft_put_sub_str(specs);
		ft_put_width(specs);
	}
	else
	{
		ft_put_width(specs);
		ft_put_sign(specs);
		ft_put_precision(specs);
		ft_put_sub_str(specs);
	}
	free (specs->sub_str);
}
