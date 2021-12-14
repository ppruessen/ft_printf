/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:28:03 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/13 16:29:18 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static size_t	ft_put_sub_str(t_specs *specs, size_t i)
{
	if (specs->precision_dot == true)
	{
		while (i < specs->precision && specs->sub_str[i] != '\0')
		{
			specs->overall_length += write(1, &specs->sub_str[i], 1);
			i++;
		}
	}
	else
	{
		while (specs->sub_str[i] != '\0')
		{
			specs->overall_length += write(1, &specs->sub_str[i], 1);
			i++;
		}
	}
	return (i);
}

static size_t	ft_put_rest(t_specs *specs, size_t i, char to_print)
{
	int	length;

	if (specs->minus == true)
	{
		while (i < specs->width)
		{
			specs->overall_length += write(1, &to_print, 1);
			i++;
		}
	}
	else
	{
		length = specs->width - ft_strlen(specs->sub_str);
		if (length >= 0)
		{
			while ((int)i < length)
			{
				specs->overall_length += write(1, &to_print, 1);
				i++;
			}
		}
	}
	return (i);
}

void	ft_handle_str(t_specs *specs)
{
	size_t	i;

	specs->sub_str = va_arg(specs->args, char *);
	i = 0;
	if (specs->sub_str == NULL)
		specs->sub_str = "(null)";
	if (specs->minus == true)
	{
		i = ft_put_sub_str(specs, i);
		i = ft_put_rest(specs, i, ' ');
	}
	else
	{
		ft_put_rest(specs, i, ' ');
		i = ft_put_sub_str(specs, i);
	}
}
