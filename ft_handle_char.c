/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:11:11 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/14 22:11:34 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"ft_printf.h"

static void	ft_put_width(t_specs *specs)
{
	int	length;

	length = specs->width - 1;
	if (length > 0)
	{
		while (length)
		{
			specs->overall_length += write(1, " ", 1);
			length--;
		}	
	}
}

void	ft_handle_char(t_specs *specs)
{
	char	char_to_print;

	char_to_print = va_arg(specs->args, int);
	if (specs->minus == true)
	{
		ft_put_char(specs, 0, char_to_print);
		ft_put_width(specs);
	}
	else
	{
		ft_put_width(specs);
		ft_put_char(specs, 0, char_to_print);
	}
}
