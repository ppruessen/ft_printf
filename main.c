/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:15:16 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/14 22:07:37 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<limits.h>
#include<assert.h>
#include"ft_printf.h"

int	main(void)
{
	int	result_ft;
	int	result_org;
/*
*	Testcases mit s%
*/
//	ft_printf("%s", "Hallo Welt");
/*	Test 1 */
	write(1, "\nTest 1\nGot		:'", 16);
	result_ft = ft_printf("%-.5s", "Hallo Welt");
	printf("'\nExpected	:'");
	result_org = printf("%-.5s", "Hallo Welt");
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);
/*	Test 2 */
	write(1, "\nTest 2\nGot		:'", 16);
	ft_printf("%-.s", "Hallo Welt");
	printf("'\nExpected	:'");
	printf("%-.s", "Hallo Welt");
	printf("'\n");
/*	Test 3 */
	write(1, "\nTest 3\nGot		:'", 16);
	ft_printf("%-.1s", "Hallo Welt");
	printf("'\nExpected	:'");
	printf("%-.1s", "Hallo Welt");
	printf("'\n");
/*	Test 4 */
	write(1, "\nTest 4\nGot		:'", 16);
	ft_printf("%-.11s", "Hallo Welt");
	printf("'\nExpected	:'");
	printf("%-.11s", "Hallo Welt");
	printf("'\n");

/*	Test 5 */
	write(1, "\nTest 5\nGot		:'", 16);
	ft_printf("%-.20s", "Hallo Welt");
	printf("'\nExpected	:'");
	printf("%-.20s", "Hallo Welt");
	printf("'\n");

	/*	Test 6 */
	write(1, "\nTest 6\nGot		:'", 16);
	ft_printf("%-5.20s", "Hallo Welt");
	printf("'\nExpected	:'");
	printf("%-5.20s", "Hallo Welt");
	printf("'\n");

/*	Test 7 */
	write(1, "\nTest 7\nGot		:'", 16);
	ft_printf("%-15.20s", "Hallo Welt");
	printf("'\nExpected	:'");
	printf("%-15.20s", "Hallo Welt");
	printf("'\n");

	/*	Test 8 */
	write(1, "\nTest 8\nGot		:'", 16);
	ft_printf("%5s", "Hallo Welt");
	printf("'\nExpected	:'");
	printf("%5s", "Hallo Welt");
	printf("'\n");

/*	Test 9 */
	write(1, "\nTest 9\nGot		:'", 16);
	ft_printf("%15s", "Hallo Welt");
	printf("'\nExpected	:'");
	printf("%15s", "Hallo Welt");
	printf("'\n");

/*	Test 10 */
	write(1, "\nTest 10\nGot		:'", 17);
	result_ft = ft_printf(" %s ", "-");
	printf("'\nExpected	:'");
	result_org = printf(" %s ", "-");
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 11 */
	write(1, "\nTest 11\nGot		:'", 17);
	result_ft = ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	printf("'\nExpected	:'");
	result_org = printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 12 */
	write(1, "\nTest 12\nGot		:'", 17);
	result_ft = ft_printf("%-d", -5);
	printf("'\nExpected	:'");
	result_org = printf("%-d", -5);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 13 */
	write(1, "\nTest 13\nGot		:'", 17);
	result_ft = ft_printf("%-d", 5);
	printf("'\nExpected	:'");
	result_org = printf("%-d", 5);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 14 */
	write(1, "\nTest 14\nGot		:'", 17);
	result_ft = ft_printf("%d", 5);
	printf("'\nExpected	:'");
	result_org = printf("%d", 5);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 15 */
	write(1, "\nTest 15\nGot		:'", 17);
	result_ft = ft_printf("%d", -5);
	printf("'\nExpected	:'");
	result_org = printf("%d", -5);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 16 */
	write(1, "\nTest 16\nGot		:'", 17);
	result_ft = ft_printf("%+d", 5);
	printf("'\nExpected	:'");
	result_org = printf("%+d", 5);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 17 */
	write(1, "\nTest 17\nGot		:'", 17);
	result_ft = ft_printf("%+d", -5);
	printf("'\nExpected	:'");
	result_org = printf("%+d", -5);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 18 */
	write(1, "\nTest 18\nGot		:'", 17);
	result_ft = ft_printf(" %04d ", 9);
	printf("'\nExpected	:'");
	result_org = printf(" %04d ", 9);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 19 */
	write(1, "\nTest 19\nGot		:'", 17);
	result_ft = ft_printf(" %04d ", -9);
	printf("'\nExpected	:'");
	result_org = printf(" %04d ", -9);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 20 */
	write(1, "\nTest 20\nGot		:'", 17);
	result_ft = ft_printf(" %-2d ", -1);
	printf("'\nExpected	:'");
	result_org = printf(" %-2d ", -1);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 21 */
	write(1, "\nTest 21\nGot		:'", 17);
	result_ft = ft_printf(" %-3d ", -101);
	printf("'\nExpected	:'");
	result_org = printf(" %-3d ", -101);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 22 */
	write(1, "\nTest 22\nGot		:'", 17);
	result_ft = ft_printf(" %.4d ", 15);
	printf("'\nExpected	:'");
	result_org = printf(" %.4d ", 15);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 23 */
	write(1, "\nTest 23\nGot		:'", 17);
	result_ft = ft_printf(" %.3d ", -99);
	printf("'\nExpected	:'");
	result_org = printf(" %.3d ", -99);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 24 */
	write(1, "\nTest 24\nGot		:'", 17);
	result_ft = ft_printf(" %.1d ", 99);
	printf("'\nExpected	:'");
	result_org = printf(" %.1d ", 99);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 25 */
	write(1, "\nTest 25\nGot		:'", 17);
	result_ft = ft_printf("%0014.2d%020d%0002.d%000.5d", (int)-2147483648, 3, 30, -1);
	printf("'\nExpected	:'");
	result_org = printf("%0014.2d%020d%0002.d%000.5d", (int)-2147483648, 3, 30, -1);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 26 */
	write(1, "\nTest 26\nGot		:'", 17);
	result_ft = ft_printf("%01.3d", 0);
	printf("'\nExpected	:'");
	result_org = printf("%01.3d", 0);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 27 */
	write(1, "\nTest 27\nGot		:'", 17);
	result_ft = ft_printf("%-d", 0);
	printf("'\nExpected	:'");
	result_org = printf("%-d", 0);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 28 */
	write(1, "\nTest 28\nGot		:'", 17);
	result_ft = ft_printf("%01.2d", 0);
	printf("'\nExpected	:'");
	result_org = printf("%01.2d", 0);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 29 */
	write(1, "\nTest 29\nGot		:'", 17);
	result_ft = ft_printf("%x", 42);
	printf("'\nExpected	:'");
	result_org = printf("%x", 42);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 30 */
	write(1, "\nTest 30\nGot		:'", 17);
	result_ft = ft_printf("%X", 424242);
	printf("'\nExpected	:'");
	result_org = printf("%X", 424242);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 31 */
	write(1, "\nTest 31\nGot		:'", 17);
	result_ft = ft_printf(" %#x ", 9);
	printf("'\nExpected	:'");
	result_org = printf(" %#x ", 9);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 32 */
	write(1, "\nTest 32\nGot		:'", 17);
	result_ft = ft_printf(" %#x ", -100);
	printf("'\nExpected	:'");
	result_org = printf(" %#x ", -100);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 33 */
	write(1, "\nTest 33\nGot		:'", 17);
	result_ft = ft_printf(" %#x ", 0);
	printf("'\nExpected	:'");
	result_org = printf(" %#x ", 0);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);
	
/*	Test 34 */
	write(1, "\nTest 34\nGot		:'", 17);
	result_ft = ft_printf(" %#x ", LONG_MIN);
	printf("'\nExpected	:'");
	result_org = printf(" %#x ", LONG_MIN);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 35 */
	write(1, "\nTest 35\nGot		:'", 17);
	result_ft = ft_printf(" %-4x ", 9);
	printf("'\nExpected	:'");
	result_org = printf(" %-4x ", 9);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);
	
/*	Test 36 */
	write(1, "\nTest 36\nGot		:'", 17);
	result_ft = ft_printf(" %-1x ", 99);
	printf("'\nExpected	:'");
	result_org = printf(" %-1x ", 99);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 37 */
	write(1, "\nTest 37\nGot		:'", 17);
	result_ft = ft_printf(" %04x ", 9);
	printf("'\nExpected	:'");
	result_org = printf(" %04x ", 9);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);
	
/*	Test 38 */
	write(1, "\nTest 38\nGot		:'", 17);
	result_ft = ft_printf(" %012x ", LONG_MIN);
	printf("'\nExpected	:'");
	result_org = printf(" %012x ", LONG_MIN);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 39 */
	write(1, "\nTest 39\nGot		:'", 17);
	result_ft = ft_printf(" %-3c", '0' - 256);
	printf("'\nExpected	:'");
	result_org = printf(" %-3c", '0' - 256);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);
	
/*	Test 40 */
	write(1, "\nTest 40\nGot		:'", 17);
	result_ft = ft_printf(" %-1c %-2c %-3c ", 0, '1', '2');
	printf("'\nExpected	:'");
	result_org = printf(" %-1c %-2c %-3c ", 0, '1', '2');
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);

/*	Test 41 */
	write(1, "\nTest 41\nGot		:'", 17);
	result_ft = ft_printf(" %-11p %-12p ", INT_MIN, INT_MAX);
	printf("'\nExpected	:'");
	result_org = printf(" %-11p %-12p ", INT_MIN, INT_MAX);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);
	
/*	Test 42 */
	write(1, "\nTest 42\nGot		:'", 17);
	result_ft = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("'\nExpected	:'");
	result_org = printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("'\n");
	printf("Return ft: %d -- Return org: %d\n", result_ft, result_org);
	
	return (0);
}
