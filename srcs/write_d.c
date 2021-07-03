/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 21:28:06 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/13 14:52:09 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int				get_size(long long int n)
{
	int		res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static void				write_local_char(t_printf *s, char c, char m, \
long long int n)
{
	int		i;

	i = ((s->plus == 1 || s->space == 1 || m == 1) ? 1 : 0);
	if (s->is_rigor == 1 && s->rigor == 0 && n == 0)
		putchar_char(c, s->width - i, s);
	else
	{
		if (s->rigor > 0 && s->rigor > s->size)
			putchar_char(c, s->width - s->rigor - i, s);
		else
			putchar_char(c, s->width - s->size - i, s);
	}
}

static void				set_write_hyphen(t_printf *s, long long int n, char m)
{
	char	*text;

	if ((s->plus == 1 || s->space == 1) && m == 0)
		putchar_fd((s->plus == 1 ? '+' : ' '), s);
	else if (m == 1)
		putchar_fd('-', s);
	if (s->rigor > 0)
		putchar_char('0', s->rigor - s->size, s);
	n = (n < 0 ? -n : n);
	if (n == 0 && s->is_rigor == 1 && s->rigor == 0)
		write_local_char(s, ' ', m, n);
	else
	{
		text = ft_itoa(n);
		putstr_fd(text, s);
		clear_var_1(text);
		write_local_char(s, ' ', m, n);
	}
}

static void				set_write(t_printf *s, long long int n, char m)
{
	char	*text;
	int		l;

	n = (n < 0 ? -n : n);
	if (s->zero == 0 || (s->zero == 1 && s->is_rigor == 1))
		write_local_char(s, ' ', m, n);
	if ((s->plus == 1 || s->space == 1) && m == 0)
		putchar_fd((s->plus == 1 ? '+' : ' '), s);
	else if (m == 1)
		putchar_fd('-', s);
	l = ((s->plus == 1 || s->space == 1 || m == 1) ? 1 : 0);
	if (s->rigor > 0)
		putchar_char('0', s->rigor - s->size, s);
	else if (s->zero == 1 && s->is_rigor == 0)
		putchar_char('0', s->width - s->size - l, s);
	if (n == 0 && s->is_rigor == 1 && s->rigor == 0)
		return ;
	else
	{
		text = ft_itoa(n);
		putstr_fd(text, s);
		clear_var_1(text);
	}
}

int						write_d(t_printf *s)
{
	long long int	res;

	res = 0;
	if (s->type == 'd' || s->type == 'i')
		res = (long long int)va_arg(s->va, int);
	else if (s->type == 'u')
		res = (long long int)va_arg(s->va, unsigned int);
	s->size = get_size(res);
	if (res == 0 && s->is_rigor == 1 && s->rigor == 0 && s->width == 0)
	{
		if (s->plus == 1)
			putchar_fd('+', s);
		return (0);
	}
	if (s->hyphen == 1)
		set_write_hyphen(s, res, (res < 0) ? 1 : 0);
	else
		set_write(s, res, (res < 0) ? 1 : 0);
	return (0);
}
