/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 15:20:19 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/04 20:52:20 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_width(t_printf *s, char *filter)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (ft_strchr(FLAGS, filter[i]))
		i++;
	if (filter[i] == '*')
	{
		res = va_arg(s->va, int);
		if (res < 0)
		{
			res = -res;
			s->hyphen = 1;
		}
	}
	else
	{
		while (filter[i] >= '0' && filter[i] <= '9')
		{
			res = res * 10 + (filter[i] - '0');
			i++;
		}
	}
	return (res);
}
