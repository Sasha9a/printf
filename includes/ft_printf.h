/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 19:02:53 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/13 21:47:07 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define FLAGS "-0# +"
# define WIDTH "*0123456789"
# define TYPE "cspdiuxX%"
# define SPECIAL "\n\t\v\f"

typedef struct			s_printf
{
	va_list		va;
	int			len;
	int			size;
	char		type;
	int			width;
	int			rigor;
	char		is_rigor;
	char		hyphen;
	char		plus;
	char		space;
	char		lattice;
	char		zero;
}						t_printf;

int						ft_printf(const char *s, ...);
void					clear_struct(t_printf *s);
int						distributor(t_printf *s, char *text);
int						write_percent(t_printf *s);
int						write_p(t_printf *s);
int						write_d(t_printf *s);
int						write_c(t_printf *s);
int						write_s(t_printf *s);
int						write_x(t_printf *s);
void					putstr_fd(char *s, t_printf *t);
void					putchar_fd(char c, t_printf *t);
void					putchar_char(char c, int len, t_printf *t);
int						get_width(t_printf *s, char *filter);
int						get_rigor(t_printf *s, char *filter);
char					*ft_itoa_base(unsigned long long n, char *base);
int						clear_var_1(char *s);
int						clear_var_2(char *s, char *s1);

#endif
