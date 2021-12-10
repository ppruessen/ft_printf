/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:57:40 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/10 00:17:47 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_eval_flags(t_specs *specs, const char *string, int i)
{
	while (string[i] == '-' || string[i] == '#' || string[i] == '+'
		|| string[i] == '0' || string[i] == ' ')
	{
		if (string[i] == '-')
			specs->minus = true;
		else if (string[i] == '#')
			specs->hash = true;
		else if (string[i] == '+')
			specs->sign = '+';
		else if (string[i] == '0')
			specs->zero = true;
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
		specs->precision_dot = true;
		specs->precision = ft_atoi(&string[i]);
		while (string[i] >= '0' && string[i] <= '9')
		{
			i++;
		}
	}
	return (i);
}
