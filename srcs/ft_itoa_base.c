/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:10:18 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/04 10:10:45 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_itoa_base(unsigned long long n, char *base)
{
	char					*res;
	int						len;
	unsigned long long		tmp;
	unsigned int			base_length;

	base_length = ft_strlen(base);
	len = 1;
	tmp = n;
	while (tmp >= base_length && (tmp /= base_length))
		len++;
	tmp = n;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	while (tmp >= base_length)
	{
		res[--len] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--len] = base[tmp % base_length];
	return (res);
}
