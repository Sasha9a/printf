/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rigor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:32:00 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/04 22:41:41 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_param(t_printf *s)
{
	int		res;

	res = va_arg(s->va, int);
	if (res < 0)
	{
		res = 0;
		s->is_rigor = 0;
	}
	return (res);
}

int			get_rigor(t_printf *s, char *filter)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (ft_strchr(FLAGS, filter[i]) || ft_strchr(WIDTH, filter[i]))
		i++;
	if (filter[i] == '.')
	{
		s->is_rigor = 1;
		i++;
		if (filter[i] == '*')
			res = get_param(s);
		else
		{
			while (filter[i] >= '0' && filter[i] <= '9')
			{
				res = res * 10 + (filter[i] - '0');
				i++;
			}
		}
	}
	return (res);
}
