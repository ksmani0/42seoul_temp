/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:06:17 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/30 17:38:22 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

char				g_hex_b[17] = "0123456789ABCDEF";
char				g_hex_s[17] = "0123456789abcdef";

/*
*flag: +-0' '*#. | spec: diuxXcsp%nfge | prec: precision
*len: hHlL(signed char~sigend long long)
*/

typedef unsigned char		t_uchar;
typedef unsigned short int	t_usint;
typedef unsigned int		t_uint;
typedef unsigned long int	t_ulint;
typedef unsigned long long int	t_ullint;
typedef short int		t_sint;
typedef long int		t_lint;
typedef long long int		t_llint;
typedef long double		t_ldble;

typedef struct			s_format
{
	char			*str;
	char			flag[7];
	char			spec;
	char			if_num[21];
	char			len;
	va_list			ap;
	int			width;
	int			prec;
	int			size;
	int			nums;
}				t_format;

/*
*m:mantissa | e:exponent | s:sign
*/

typedef union			u_dble
{
	double			value;
	struct
	{
		size_t		m : 52;
		size_t		e : 11;
		size_t		s : 1;
	}			s_int;
	size_t			total_v;
}				t_dble;

typedef struct			s_dble
{
	char			sign;
	char			*s_div;
	char			*d_bit;
	char			*s_mod;
	char			*m_bit;
	size_t			d_len;
	size_t			m_len;
	char			*out;
	size_t			out_mlen;
	int			p_idx;/*index until 0div*/
	char			*e;
	char			esign;
	int			e_int;

}				t_sble;

typedef struct			s_deci
{
	char			s[1076];/*52+1+1022 + 1*/
	size_t			len;
}				t_deci;

/*
*****ft_printf.c*****
*/

t_format	*initial_malloc(t_format **list);
void		print_char(t_format *list);
void		initial_part(t_format *list);
int		str_or_format(t_format *list);
int		ft_printf(const char *format, ...);

/*
*****check_func.c*****
*/

void		if_flag_check(t_format *list);
void		check_width_star(t_format *list);
void		check_prec_star(t_format *list);
void		check_length(t_format *list);
int		check_spec(t_format *list);

/*
*****print_int.c*****
*/

size_t		count_num_len(long num, t_format *list);
void		input_list_num(t_format *list, long num, size_t len);
void	fill_space_or_zero(int *i, int limit, char *out, char s_or_z);
void	output_int_ngf(char *out, t_format *list, size_t len);
void		output_int(char *out, t_format *list, size_t len);
int			print_s_int(t_format *list);
int	output_spec(t_format *list);

/*
*****print_uint.c*****
*/

int			print_s_uint(t_format *list);
int			print_s_char(t_format *list);
size_t		parse_input_hex(unsigned int x, t_format *list);
int			print_s_octal(t_format *list);
void		print_s_number(t_format *list);

/*
*****print_f.c*****
*/

int	get_div_decimal(t_dble *dble, t_sble *sble, int len)
int	parse_div(t_dble *dble, t_sble *sble)
int	check_inf_nan(t_dble dble, t_format *list)
int	free_sble(int error_or_not, t_sble *sble)
int	print_feg(t_format *list)

/*
*****parse_mod.c*****
*/

void	input_div_pow(t_deci *pow)
void	input_div_sum(char bit, t_deci *pow, t_deci *sum)
void	fill_mod_bit(t_dble *dble, t_sble *sble, int len)
int	get_mod_decimal(t_dble *dble, t_sble *sble, int len)
int	parse_mod(t_dble *dble, t_sble *sble)

/*
*****input_mod.c*****
*/

void	input_mod_pow(t_deci *pow)
void	input_mod_sum(char bit, t_deci *pow, t_deci *sum)

/*
*****get_f_str.c*****
*/

void	rounding_meet_five(t_sble *ret, int prec)
void	round_up(t_sble *ret, int prec)
void	round_f(t_format *list, t_sble *ret)
int	get_f_str(t_format *list, t_dble *dble, t_sble *sble)//need

/*
*****get_e_str.c*****
*/


int	get_e_str(t_format *list, t_dble *dble, t_sble *sble)

#endif
