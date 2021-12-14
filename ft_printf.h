/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:29:03 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/14 16:54:41 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

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
	char	*sub_str;
	int		overall_length;
}	t_specs;

int				ft_printf(const char *string, ...);
int				ft_eval_specs(t_specs *specs, const char *string, int i);
int				ft_atoi(const char *str);
void			ft_handle_str(t_specs *specs);
size_t			ft_strlen(const char *s);
void			ft_handle_decimal(t_specs *specs);
char			*ft_itoa_with_sign(t_specs *specs, int n);
size_t			ft_put_char(t_specs *specs, size_t i, char to_print);
void			ft_handle_udecimal(t_specs *specs);
char			*ft_uitoa(unsigned int n);
void			ft_handle_hex(t_specs *specs, char up_or_low);
char			*ft_uitohex(unsigned int n);

#endif
