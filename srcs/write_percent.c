/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:40:25 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/04 17:51:46 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			write_percent(t_printf *s)
{
	s->size = 1;
	if (s->hyphen == 1)
	{
		putchar_fd('%', s);
		putchar_char(' ', s->width - 1, s);
	}
	else
	{
		if (s->zero == 1)
			putchar_char('0', s->width - 1, s);
		else
			putchar_char(' ', s->width - 1, s);
		putchar_fd('%', s);
	}
	return (0);
}
