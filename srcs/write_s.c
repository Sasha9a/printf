/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:22:35 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/13 11:47:45 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			set_write_hyphen(t_printf *s, char *c)
{
	if (s->rigor != 0 && s->rigor < s->size)
	{
		write(1, c, s->rigor);
		s->len += s->rigor;
		putchar_char(' ', s->width - s->rigor, s);
	}
	else
	{
		if (s->is_rigor == 1 && s->rigor == 0)
			putchar_char(' ', s->width, s);
		else
		{
			write(1, c, s->size);
			s->len += s->size;
			putchar_char(' ', s->width - s->size, s);
		}
	}
}

static void			set_write(t_printf *s, char *c)
{
	if (s->rigor != 0 && s->rigor < s->size)
	{
		putchar_char(' ', s->width - s->rigor, s);
		write(1, c, s->rigor);
		s->len += s->rigor;
	}
	else
	{
		if (s->is_rigor == 1 && s->rigor == 0)
			putchar_char(' ', s->width, s);
		else
		{
			if (s->zero == 1)
				putchar_char('0', s->width - s->size, s);
			else
				putchar_char(' ', s->width - s->size, s);
			write(1, c, s->size);
			s->len += s->size;
		}
	}
}

int					write_s(t_printf *s)
{
	char		*res;

	res = va_arg(s->va, char *);
	res = (res == NULL ? ft_strdup("(null)") : ft_strdup(res));
	s->size = (int)ft_strlen(res);
	if (s->hyphen == 1)
		set_write_hyphen(s, res);
	else
		set_write(s, res);
	clear_var_1(res);
	return (0);
}
