/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 19:09:17 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/06 12:42:06 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_printf	param;

	if (!s)
		return (-1);
	va_start(param.va, s);
	param.len = 0;
	clear_struct(&param);
	if (distributor(&param, (char *)s) == -1)
		return (-1);
	va_end(param.va);
	return (param.len);
}
