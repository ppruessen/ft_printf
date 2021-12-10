/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:10:47 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/10 00:57:38 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/libft.h"

// A format specifier follows this prototype:
// %[flags][width][.precision][length]type
// flags: "0", "-", ".", "#", "+", " "(space)
// specifiers: c, s, d, i, u, p, x, X, %

typedef struct s_specs
{
	va_list	args;		//argument to print out
	bool	minus;
	bool	zero;
	bool	hash;
	char	sign;
	size_t	width;
	bool	precision_dot;
	size_t	precision;
	int		overall_length;
}	t_specs;

int		ft_printf(const char *string, ...);
void	ft_initialise_specs(t_specs *specs);

// EVAL SYNTAX
int		ft_eval_flags(t_specs *specs, const char *string, int i);
int		ft_eval_width(t_specs *specs, const char *string, int i);
int		ft_eval_precision(t_specs *specs, const char *string, int i);

// HANDLE TYPES
void	ft_handle_decimal(t_specs *specs);

// PUT DECIMAL
size_t	ft_put_sign(t_specs *specs, size_t i);
size_t	ft_put_rest(t_specs *specs, size_t len, size_t i, char char_to_put);
size_t	ft_put_sub_str(t_specs *specs, char *sub_str, size_t i);

// HELPERS
int		ft_new_str_length(t_specs *specs, int new_length);
char	*ft_create_new_str(t_specs *specs, char *nbr_str,
			char *new_nbr_str, size_t new_length);

#endif