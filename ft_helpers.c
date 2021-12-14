/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 04:28:42 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/14 04:31:06 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_char(t_specs *specs, size_t i, char to_print)
{
	specs->overall_length += write(1, &to_print, 1);
	i++;
	return (i);
}
