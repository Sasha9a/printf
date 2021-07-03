/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 11:34:56 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/05 11:04:34 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	clear_struct(t_printf *s)
{
	s->size = 0;
	s->type = 0;
	s->width = 0;
	s->rigor = 0;
	s->is_rigor = 0;
	s->hyphen = 0;
	s->plus = 0;
	s->space = 0;
	s->lattice = 0;
	s->zero = 0;
}
