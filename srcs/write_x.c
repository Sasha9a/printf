/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:13:22 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/13 13:43:54 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		write_local_char(t_printf *s, char c, unsigned int n)
{
	int		i;

	i = ((s->lattice == 1 && n != 0) ? 2 : 0);
	if (s->rigor == 0)
		putchar_char(c, s->width - s->size - i, s);
	else
	{
		if (s->rigor > s->size)
			putchar_char(c, s->width - s->rigor - i, s);
		else
			putchar_char(c, s->width - s->size - i, s);
	}
}

static void		set_write_hyphen(t_printf *s, char *n, unsigned int i)
{
	if (s->lattice == 1 && i != 0)
		putstr_fd(((s->type == 'x') ? "0x" : "0X"), s);
	if (s->rigor != 0)
		putchar_char('0', s->rigor - s->size, s);
	if (i == 0 && s->is_rigor == 1 && s->rigor == 0)
		putchar_char(' ', s->size, s);
	else
		putstr_fd(n, s);
	write_local_char(s, ' ', i);
}

static void		set_write(t_printf *s, char *n, unsigned int i)
{
	int		l;

	l = ((s->lattice == 1 && i != 0) ? 2 : 0);
	if (s->zero == 0 || (s->zero == 1 && s->is_rigor == 1))
		write_local_char(s, ' ', i);
	if (s->lattice == 1 && i != 0)
		putstr_fd(((s->type == 'x') ? "0x" : "0X"), s);
	if (s->rigor > 0)
		putchar_char('0', s->rigor - s->size, s);
	else if (s->zero == 1)
	{
		if (s->rigor > s->size)
			putchar_char('0', s->width - s->rigor - l, s);
		else
			putchar_char('0', s->width - s->size - l, s);
	}
	if (i == 0 && s->is_rigor == 1 && s->rigor == 0)
		putchar_char(' ', s->size, s);
	else
		putstr_fd(n, s);
}

int				write_x(t_printf *s)
{
	unsigned int	res;
	char			*text;

	res = va_arg(s->va, unsigned int);
	if (s->type == 'x')
		text = ft_itoa_base((unsigned long long)res, "0123456789abcdef");
	else
		text = ft_itoa_base((unsigned long long)res, "0123456789ABCDEF");
	if (!text)
		return (clear_var_1(text));
	s->size = (int)ft_strlen(text);
	if (res == 0 && s->is_rigor == 1 && s->rigor == 0 && s->width == 0)
	{
		clear_var_1(text);
		return (0);
	}
	if (s->hyphen == 1)
		set_write_hyphen(s, text, res);
	else
		set_write(s, text, res);
	clear_var_1(text);
	return (0);
}
