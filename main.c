/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:33:41 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/10 00:17:23 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%020.10d", -42000);
	printf("\n");
	ft_printf("%020.10d", -42000);
	printf("\n");
	printf("\n");
	printf("%0014.2d", (int)-2147483648);
	printf("\n");
	ft_printf("%0014.2d", (int)-2147483648);
	printf("\n");
	printf("\n");
	printf("%014.2d", (int)-2147483648);
	printf("\n");
	ft_printf("%014.2d", (int)-2147483648);
}
