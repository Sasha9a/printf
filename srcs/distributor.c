/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distributor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 11:41:42 by jlyessa           #+#    #+#             */
/*   Updated: 2020/06/13 19:42:42 by jlyessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		set_write(t_printf *s, int i)
{
	if (i == 0)
		return (0);
	if (s->type == '%')
		return (write_percent(s));
	else if (s->type == 'p')
		return (write_p(s));
	else if (s->type == 'd' || s->type == 'i' || s->type == 'u')
		return (write_d(s));
	else if (s->type == 'c')
		return (write_c(s));
	else if (s->type == 's')
		return (write_s(s));
	else if (s->type == 'x' || s->type == 'X')
		return (write_x(s));
	else if (ft_strchr(SPECIAL, s->type))
	{
		putchar_fd('%', s);
		putchar_fd(s->type, s);
	}
	return (0);
}

static void		get_filter(t_printf *s, char *filter)
{
	int		i;

	i = 0;
	while (ft_strchr(FLAGS, filter[i]))
	{
		if (filter[i] == '-')
			s->hyphen = 1;
		if (filter[i] == '+')
			s->plus = 1;
		if (filter[i] == ' ')
			s->space = 1;
		if (filter[i] == '#')
			s->lattice = 1;
		if (filter[i] == '0')
			s->zero = 1;
		i++;
	}
	s->width = get_width(s, filter);
	s->rigor = get_rigor(s, filter);
	i = ft_strlen(filter);
	s->type = filter[i - 1];
}

static int		set_filter(t_printf *s, char **text)
{
	char	*t;
	char	*c;
	char	*filter;

	if (!(c = ft_calloc(2, sizeof(char))))
		return (clear_var_1(c));
	if (!(filter = ft_strdup("")))
		return (clear_var_2(c, filter));
	while (**text)
	{
		t = filter;
		c[0] = **text;
		if (!(filter = ft_strjoin(t, c)))
			return (clear_var_2(c, filter));
		(*text)++;
		clear_var_1(t);
		if (ft_strchr(TYPE, c[0]) || ft_strchr(SPECIAL, c[0]))
			break ;
	}
	get_filter(s, filter);
	if (set_write(s, ft_strlen(filter)) == -1)
		return (clear_var_2(c, filter));
	clear_var_2(c, filter);
	clear_struct(s);
	return (0);
}

int				distributor(t_printf *s, char *text)
{
	while (*text)
	{
		if (*text != '%')
		{
			putchar_fd(*text, s);
			text++;
			continue ;
		}
		text++;
		if (set_filter(s, &text) == -1)
			return (-1);
	}
	return (0);
}
