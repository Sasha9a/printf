/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 17:05:28 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/13 12:34:30 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		set_write_hyphen(t_printf *s, unsigned long long i, char *text)
{
	putstr_fd("0x", s);
	if (i == 0 && s->is_rigor == 1 && s->rigor == 0)
		return ;
	if (s->rigor != 0)
		putchar_char('0', s->rigor - s->size, s);
	putstr_fd(text, s);
	if (s->rigor != 0)
		putchar_char(' ', s->width - s->rigor - 2, s);
	else
		putchar_char(' ', s->width - s->size - 2, s);
}

static void		set_write(t_printf *s, unsigned long long i, char *text)
{
	if (s->rigor != 0 && s->rigor > s->size)
		putchar_char(' ', s->width - s->rigor - 2, s);
	else
		putchar_char(' ', s->width - s->size - 2, s);
	putstr_fd("0x", s);
	if (i == 0 && s->is_rigor == 1 && s->rigor == 0)
		return ;
	if (s->rigor != 0)
		putchar_char('0', s->rigor - s->size, s);
	putstr_fd(text, s);
}

int				write_p(t_printf *s)
{
	char					*res;
	unsigned long long int	i;

	i = (unsigned long long)va_arg(s->va, void *);
	res = ft_itoa_base(i, "0123456789abcdef");
	if (!res)
		return (clear_var_1(res));
	s->size = (int)ft_strlen(res);
	if (s->hyphen == 1)
		set_write_hyphen(s, i, res);
	else
		set_write(s, i, res);
	clear_var_1(res);
	return (0);
}
