/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:10:51 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/09 00:49:33 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_initialise_specs(t_specs *specs)
{
	specs->hash = false;
	specs->minus = false;
	specs->sign = '0';
	specs->zero = false;
	specs->width = 0;
	specs->precision_dot = false;
	specs->precision = 0;
}

int	ft_eval_type(t_specs *specs, const char *string, int i)
{
	if (string[i] == 'c')
		printf("'c'\n");
	else if (string[i] == 's')
		printf("'s'\n");
	else if (string[i] == 'p')
		printf("'p'\n");
	else if (string[i] == 'd')
		ft_handle_decimal(specs);
	else if (string[i] == 'i')
		ft_handle_decimal(specs);
	else if (string[i] == 'u')
		ft_handle_decimal(specs);
	else if (string[i] == 'X')
		printf("'X'\n");
	else if (string[i] == 'x')
		printf("'x'\n");
	return (i + 1);
}

int	ft_eval_specs(t_specs *specs, const char *string, int i)
{
	if (string[i] == '%')
	{
		specs->overall_length += write(1, "%", 1);
		return (i);
	}
	i = ft_eval_flags(specs, string, i);
	i = ft_eval_width(specs, string, i);
	i = ft_eval_precision(specs, string, i);
	i = ft_eval_type(specs, string, i);
	return (i);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	t_specs	*specs;

	specs = (t_specs *)malloc(sizeof(t_specs));
	if (!specs)
		return (-1);
	ft_initialise_specs(specs);
	specs->overall_length = 0;
	va_start(specs->args, string);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i = ft_eval_specs(specs, string, i + 1);
			ft_initialise_specs(specs);
		}
		else
		{
			specs->overall_length += write(1, &string[i], 1);
			i++;
		}
	}
	i = specs->overall_length;
	free (specs);
	return (i);
}
