/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:02:29 by jlyessa           #+#    #+#             */
/*   Updated: 2020/05/07 22:02:24 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (*big && len-- >= i)
	{
		if (!ft_memcmp(big, little, i))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
