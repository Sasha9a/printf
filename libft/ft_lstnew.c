/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:31:09 by jlyessa           #+#    #+#             */
/*   Updated: 2020/05/10 14:11:39 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
