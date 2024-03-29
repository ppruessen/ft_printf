/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_specs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:36:57 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/16 01:58:03 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_eval_flags(t_specs *specs, const char *string, int i)
{
	while (string[i] == '-' || string[i] == '#' || string[i] == '+'
		|| string[i] == '0' || string[i] == ' ')
	{
		if (string[i] == '-')
			specs->minus = 1;
		else if (string[i] == '#')
			specs->hash = 1;
		else if (string[i] == '+')
			specs->sign = '+';
		else if (string[i] == '0')
			specs->zero = 1;
		else if (string[i] == ' ' && specs->sign != '+')
			specs->sign = ' ';
		i++;
	}
	return (i);
}

int	ft_eval_width(t_specs *specs, const char *string, int i)
{	
	specs->width = ft_atoi(&string[i]);
	while (string[i] >= '0' && string[i] <= '9')
	{
		i++;
	}
	return (i);
}

int	ft_eval_precision(t_specs *specs, const char *string, int i)
{
	if (string[i] == '.')
	{
		i++;
		specs->precision_dot = 1;
		specs->precision = ft_atoi(&string[i]);
		while (string[i] >= '0' && string[i] <= '9')
		{
			i++;
		}
	}
	return (i);
}

int	ft_eval_type(t_specs *specs, const char *string, int i)
{
	if (string[i] == '%')
		specs->overall_length += write(1, "%", 1);
	else if (string[i] == 'c')
		ft_handle_char(specs);
	else if (string[i] == 's')
		ft_handle_str(specs);
	else if (string[i] == 'p')
		ft_handle_p(specs);
	else if (string[i] == 'd')
		ft_handle_decimal(specs);
	else if (string[i] == 'i')
		ft_handle_decimal(specs);
	else if (string[i] == 'u')
		ft_handle_udecimal(specs);
	else if (string[i] == 'X')
		ft_handle_hex(specs, string[i]);
	else if (string[i] == 'x')
		ft_handle_hex(specs, string[i]);
	return (i + 1);
}

int	ft_eval_specs(t_specs *specs, const char *string, int i)
{
	i = ft_eval_flags(specs, string, i);
	i = ft_eval_width(specs, string, i);
	i = ft_eval_precision(specs, string, i);
	i = ft_eval_type(specs, string, i);
	return (i);
}
