/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:31:56 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/05 23:05:09 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef enum	e_flag_f
{
	p2, p1r, p1b, p0, neg, dis, lc
}				t_flag_f;

typedef enum		e_flag
{
	NO_FLAG, PLUS, MINUS, SPACE, SHARP, NOLL
}					t_flag;

typedef	enum		e_datatype
{
	CHAR = 1, STR, DEC, PTR, U_DEC, OCT, HEX, HEX_B, FLOAT
}					t_datatype;

typedef enum		e_length
{
	NO_LEN, hh, h, l, ll, L
}					t_length;

typedef union		u_data
{
	long long int	i;
	unsigned char	c;
	char			*str;
	long double		d;
	size_t			pointer;

}					t_data;

typedef struct		s_str
{
	char			*buf;
	size_t			len;
}					t_str;

typedef struct		s_p_buf
{
	t_flag			flag[6];
	int				width;
	int				precision;
	t_length		d_length;
	t_datatype		d_type;
	t_data			data;
	size_t			len;
	char			*f_str;
	char			*end_find;
}					t_p_buf;

char				*find_type(t_p_buf *str, char *start, va_list *ap);
int					parse_start(char **start, va_list *ap);
void				parse_flags(t_p_buf *tmp, char *start);
void				parse_width(t_p_buf *tmp, char *start);
void				parse_precision(t_p_buf *tmp, char *start);
int					parse_length(t_p_buf *tmp, char *start);
int					addtnl_types(char c, t_p_buf *p_str);
int					ft_printf(const char *f, ...);
char				*get_char(char c);
int					type_char(char c, t_p_buf *p_str);
void				numeric(t_p_buf *p_str);
void				numeric_u(t_p_buf *p_str);
char				*get_format_str(t_p_buf *p_str, va_list *ap);
char				*ft_itoa_long(long long int n);
char				*ft_itoa_unlong(unsigned long long int n);
char				*itoa_hex(unsigned long long int i, int size);
char				*char_add(char *str, char c, int n);
char				*add_char(char *str, char c, int n);
char				*add_char2zero(char *str, char c, int n, t_p_buf *p_str);
char				*itoa_oct(unsigned long long int i);
char				*check_presicion(t_p_buf *p_str);
char				*check_width(t_p_buf *p_str, char *prec_str);
char				*sig_prec(t_p_buf *p_str, char *str, char c,
										int count, char sign);
int					find_max(int a, int b, int c);
int					hex_oct_types(char c, t_p_buf *p_str);
char				*neg_wid(t_p_buf *p_str, char *prev_s, char c);
char				*hec_oct_flags(t_p_buf *p_str, char *prev_str);
void				numeric_f(t_p_buf *p_str, va_list *ap);
char				*ft_itoa_double(long double i, int prec);
char				*d_to_s(long double i, t_flag_f *f, int prec, long long real);
char				*real_f(t_flag_f *f, char *str, int lstr);
char				*flags_f(t_flag_f *f, long double i, int prec, long long real);
char				*drob_f(char *str2, int prec, t_flag_f *f, long double i);
void				flags_f_p0(t_flag_f *f, long double i, int prec, long long real);
long double			ft_pow(long long x, int y);
char				*ft_itoa_ldouble(long double i, int prec);

#endif
