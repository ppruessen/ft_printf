/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:28:15 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/16 02:00:35 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_initialise_specs(t_specs *specs)
{
	specs->hash = 0;
	specs->minus = 0;
	specs->sign = '0';
	specs->zero = 0;
	specs->width = 0;
	specs->precision_dot = 0;
	specs->precision = 0;
	specs->sub_str = NULL;
}

int	ft_printf(const char *string, ...)
{
	t_specs	*specs;
	size_t	i;

	specs = (t_specs *)malloc(sizeof(t_specs));
	if (!specs)
		return (-1);
	ft_initialise_specs(specs);
	specs->overall_length = 0;
	va_start(specs->args, string);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%' && string[i + 1] != '\0')
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
	free (specs);
	return (specs->overall_length);
}
