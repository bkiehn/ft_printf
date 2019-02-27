/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:31:56 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/26 23:38:40 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
// # define CHAR 1
// # define STRING 2
// # define POINTER 3
// # define DEC 4
// # define OCT 5
// # define HEX 6
// # define HEX_B 7
// # define FLOAT 8

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
	long long int	i;
	unsigned char	c;
	char			*str;
	double			d;
	size_t			pointer;

}				t_data;

typedef struct	s_str
{
	char	*buf;
	size_t	len;
}				t_str;

typedef struct	s_p_buf
{
	size_t		len;
	t_flag		flag[6];
	int			width;
	int			precision;
	t_length	d_length;
	t_datatype	d_type;
	t_data 		data;
	char		*f_str;
	char		*end_find;
}				t_p_buf;

char			*find_type(t_p_buf *str, char *start, va_list *ap);
void			parse_start(t_str *tmp, char **start, va_list *ap);
void			parse_flags(t_p_buf *tmp, char *start);
void			parse_width(t_p_buf *tmp, char *start);
void			parse_precision(t_p_buf *tmp, char *start);
int				parse_length(t_p_buf *tmp, char *start);
void			add_to_buf(t_str *tmp, char c);
void			ft_realloc(t_str *str);
void			ft_rejoin(t_str *tmp, char *str);
int				ft_printf(const char *f, ...);
char			*get_char(t_p_buf *p_str);
int				type_char(char c, t_p_buf *p_str);

#endif
