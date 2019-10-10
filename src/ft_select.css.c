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

/*
**	 put the asked termcap
*/

bool put_termcaps(char *termcaps)
{
	if (ERR == tputs(termcaps, 1, ft_putchar))
	{
		ft_printf(FT_SELECT_NAME"can't print the termcaps");
		return (false);
	}
	return (true);
}

void print_in_underline(char *text)
{
	ft_putchar(' ');
	put_termcaps(g_select.term.underline);
	ft_printf("%s", text);
	put_termcaps(g_select.term.clean);
	ft_putchar(' ');
}

void print_in_reverse(char *text)
{
	ft_putchar(' ');
	put_termcaps(g_select.term.reverse);
	ft_printf("%s", text);
	put_termcaps(g_select.term.clean);
	ft_putchar(' ');
}

void print_in_underline_reverse(char *text)
{
	ft_putchar(' ');
	put_termcaps(g_select.term.reverse);
	put_termcaps(g_select.term.underline);
	ft_printf("%s", text);
	put_termcaps(g_select.term.clean);
	ft_putchar(' ');
}

void clear_screen(void)
{
	put_termcaps(g_select.term.clear_screen);
}
