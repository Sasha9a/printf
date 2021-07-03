/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:36:40 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/04 09:50:36 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					write_c(t_printf *s)
{
	char	res;

	res = (char)va_arg(s->va, unsigned int);
	s->size = 1;
	if (s->hyphen == 1)
	{
		putchar_fd(res, s);
		putchar_char(' ', s->width - 1, s);
	}
	else
	{
		putchar_char(' ', s->width - 1, s);
		putchar_fd(res, s);
	}
	return (0);
}
