/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 10:49:24 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/05 20:09:32 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	putstr_fd(char *s, t_printf *t)
{
	ft_putstr_fd(s, 1);
	t->len += (int)ft_strlen(s);
}

void	putchar_fd(char c, t_printf *t)
{
	ft_putchar_fd(c, 1);
	t->len++;
}

void	putchar_char(char c, int len, t_printf *t)
{
	int		i;

	i = 0;
	while (i < len)
	{
		putchar_fd(c, t);
		i++;
	}
}
