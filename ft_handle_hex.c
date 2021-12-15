/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:25:47 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/15 15:08:44 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"libft/libft.h"

void	ft_upper_hex(t_specs *specs, char up_or_low)
{
	size_t	i;

	if (up_or_low == 'X')
	{
		i = 0;
		while (specs->sub_str[i])
		{
			specs->sub_str[i] = ft_toupper(specs->sub_str[i]);
			i++;
		}
	}
}

void	ft_put_hex(t_specs *specs)
{
	size_t	i;
	int		length;

	if (specs->sub_str[0] == '0' && specs->precision == 0
		&& specs->precision_dot == true)
		return ;
	length = specs->precision - ft_strlen(specs->sub_str);
	if (length > 0)
	{
		while ((length > 0))
		{
			specs->overall_length += write(1, "0", 1);
			length--;
		}
	}
	i = 0;
	while (specs->sub_str[i] != '\0')
	{
		specs->overall_length += write(1, &specs->sub_str[i], 1);
		i++;
	}
}

void	ft_put_hash(t_specs *specs, char up_or_low)
{
	if (specs->hash == true && up_or_low == 'x' && specs->sub_str[0] != '0')
		specs->overall_length += write(1, "0x", 2);
	else if (specs->hash == true && up_or_low == 'X'
		&& specs->sub_str[0] != '0')
		specs->overall_length += write(1, "0X", 2);
}

void	ft_put_rest(t_specs *specs, size_t length)
{
	size_t	i;

	if (specs->sub_str[0] == '0' && specs->precision == 0
		&& specs->precision_dot == true)
		length--;
	if (specs->precision > length)
		length = specs->precision;
	if (specs->width > length)
		length = specs->width - length;
	else
		return ;
	if (specs->hash == true && specs->sub_str[0] != '0')
		length -= 2;
	i = 0;
	if (length > 0)
	{
		while (i < length)
		{
			if (specs->zero == true && specs->precision_dot == false)
				specs->overall_length += write(1, "0", 1);
			else
				specs->overall_length += write(1, " ", 1);
			i++;
		}
	}
}

void	ft_handle_hex(t_specs *specs, char up_or_low)
{
	specs->sub_str = ft_ultohex((unsigned long)
			va_arg(specs->args, unsigned int));
	ft_upper_hex(specs, up_or_low);
	if (specs->minus == true)
	{
		ft_put_hash(specs, up_or_low);
		ft_put_hex(specs);
		ft_put_rest(specs, ft_strlen(specs->sub_str));
	}
	else
	{
		ft_put_hash(specs, up_or_low);
		ft_put_rest(specs, ft_strlen(specs->sub_str));
		ft_put_hex(specs);
	}
	free (specs->sub_str);
}
