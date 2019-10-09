/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

bool get_termcaps(char *name)
{
	char *term;

	if ((term = tgetstr(name, NULL)))
	{
		tputs(term, 1, ft_putchar);
		return (true);
	}
	else
	{
		ft_printf(FT_SELECT_NAME"can't get the right termcap");
		return (false);
	}
}

void print_in_underline(char *text)
{
	get_termcaps("us");
	ft_printf("%s", text);
	get_termcaps("me");
	ft_putchar(' ');
}

void print_in_reverse(char *text)
{
	get_termcaps("mr");
	ft_printf("%s", text);
	get_termcaps("me");
	ft_putchar(' ');
}

void print_in_underline_reverse(char *text)
{
	get_termcaps("mr");
	get_termcaps("us");
	ft_printf("%s", text);
	tputs(tgetstr("me", NULL), 1, ft_putchar);
	ft_putchar(' ');
}

void clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_putchar);
}
