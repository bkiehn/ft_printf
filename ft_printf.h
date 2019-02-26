/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:31:56 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/26 23:03:08 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef enum	e_flag
{
	NO_FLAG, PLUS, MINUS, SPACE, SHARP, NOLL
}				t_flag;

typedef	enum	e_datatype
{
	CHAR = 1, STR, PTR, DEC, U_DEC, OCT, HEX, HEX_B, FLOAT
}				t_datatype;

typedef enum	e_length
{
	NO_LEN, hh, h, l, ll, L
}				t_length;

typedef union	u_data
{
	char				c;
	unsigned char		u_c;
	short				s;
	unsigned short		u_s;
	long				l;
	unsigned long		u_l;
	long long			ll;
	unsigned long long	u_ll;
	int					i;
	unsigned int		u_i;
	char				*str;
	size_t				pointer;
	double				dbl;
	long	double		l_dbl;

}				t_data;

typedef struct	s_str
{
	char	*buf;
	size_t	len;
}				t_str;

typedef struct	s_p_buf
{
	size_t		len;
	int			f_space;
	int			f_hash;
	int			f_plus;
	int			f_minus;
	int			f_zero;
	int			width;
	int			precision;
	t_length	d_length;
	t_datatype	d_type;
	t_data 		data;
	char		*f_str;
}				t_p_buf;

char			*find_type(t_p_buf *str, char *start, va_list *ap);
void			parse_start(t_str *tmp, char **start, va_list *ap);
void			parse_flags(t_p_buf *tmp, char **start);
void			parse_width(t_p_buf *tmp, char **start);
void			parse_precision(t_p_buf *tmp, char **start, char *end);
void			parse_length(t_p_buf *tmp, char *start, char *end);
void			add_to_buf(t_str *tmp, char c);
void			ft_realloc(t_str *str);
void			ft_rejoin(t_str *tmp, char *str);
int				ft_printf(const char *f, ...);
char			*get_char(t_p_buf *p_str);
int				type_char(char c, t_p_buf *p_str);
void			init_p_str(t_p_buf *p_str);
char			*ft_itoa_u(unsigned int n);

#endif
