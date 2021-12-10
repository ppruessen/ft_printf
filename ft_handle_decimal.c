/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:41:23 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/10 00:55:29 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_create_neutral_str(t_specs *specs, char *sub_str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = (char *)malloc((ft_strlen(sub_str) - 1));
	if (!new_str)
		return (NULL);
	i = 1;
	j = 0;
	while (sub_str[i])
	{
		new_str[j] = sub_str[i];
		j++;
		i++;
	}
	new_str[j] = '\0';
	free (sub_str);
	specs->sign = '-';
	return (new_str);
}

char	*ft_empty_string(void)
{
	char	*empty_str;

	empty_str = (char *)calloc(1, 1);
	return (empty_str);
}

char	*ft_create_sub_str(t_specs *specs)
{
	char		*sub_str;
	char		*new_str;
	char		*helper;
	size_t		i;

	new_str = NULL;
	sub_str = ft_itoa(va_arg(specs->args, int));
	if (sub_str[0] == '0' && specs->width >= specs->precision
		&& specs->precision_dot == true && specs->precision != 1)
	{
		free(sub_str);
		return (ft_empty_string());
	}
	if (sub_str[0] == '-')
		sub_str = ft_create_neutral_str(specs, sub_str);
	if (specs->precision > ft_strlen(sub_str))
	{
		new_str = ft_calloc((specs->precision - ft_strlen(sub_str) + 1), 1);
		if (!new_str)
			return (NULL);
		i = 0;
		while (i < (specs->precision - ft_strlen(sub_str)))
			new_str[i++] = '0';
		helper = sub_str;
		sub_str = ft_strjoin(new_str, sub_str);
		free (helper);
	}
	free (new_str);
	return (sub_str);
}

void	ft_handle_decimal(t_specs *specs)
{
	char	*sub_str;
	size_t	i;

	sub_str = ft_create_sub_str(specs);
	i = 0;
	if (specs->zero == true && specs->minus == false
		&& specs->precision_dot == false)
	{
		i = ft_put_sign(specs, i);
		i = ft_put_rest(specs, ft_strlen(sub_str), i, '0');
		i = ft_put_sub_str(specs, sub_str, i);
	}
	else if (specs->minus == true)
	{
		i = ft_put_sign(specs, i);
		i = ft_put_sub_str(specs, sub_str, i);
		i = ft_put_rest(specs, 0, i, ' ');
	}
	else
	{
		i = ft_put_rest(specs, ft_strlen(sub_str), i, ' ');
		i = ft_put_sign(specs, i);
		i = ft_put_sub_str(specs, sub_str, i);
	}
	free (sub_str);
}
