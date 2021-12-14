/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:38:23 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/14 22:23:14 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"ft_printf.h"

static void	ft_put_width(t_specs *specs)
{
	int	length;

	length = specs->width - ft_strlen(specs->sub_str) - 2;
	if (length > 0)
	{
		while (length)
		{
			specs->overall_length += write(1, " ", 1);
			length--;
		}	
	}
}

static void	ft_put_p(t_specs *specs)
{
	size_t	i;

	i = 0;
	while (specs->sub_str[i])
	{
		specs->overall_length += write(1, &specs->sub_str[i], 1);
		i++;
	}
}

void	ft_handle_p(t_specs *specs)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(specs->args, void *);
	specs->sub_str = ft_ultohex(addr);
	if (specs->minus == true)
	{
		specs->overall_length += write(1, "0x", 2);
		ft_put_p(specs);
		ft_put_width(specs);
	}
	else
	{
		ft_put_width(specs);
		specs->overall_length += write(1, "0x", 2);
		ft_put_p(specs);
	}
	free (specs->sub_str);
}
