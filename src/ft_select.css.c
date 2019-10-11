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
	if (ERR == tputs(termcaps, 1, putchar_on_fd_0))
	{
		ft_dprintf(2, FT_SELECT_NAME"can't print the termcaps");
		return (false);
	}
	return (true);
}

void print_in_underline(char *text, t_term *t)
{
	ft_putchar_fd(' ', 0);
	put_termcaps(t->underline);
	ft_dprintf(0, "%s", text);
	put_termcaps(t->clean);
	ft_putchar_fd(' ', 0);
}

void print_in_reverse(char *text, t_term *t)
{
	ft_putchar_fd(' ', 0);
	put_termcaps(t->reverse);
	ft_dprintf(0, "%s", text);
	put_termcaps(t->clean);
	ft_putchar_fd(' ', 0);
}

void print_in_underline_reverse(char *text, t_term *t)
{
	ft_putchar_fd(' ', 0);
	put_termcaps(t->reverse);
	put_termcaps(t->underline);
	ft_dprintf(0, "%s", text);
	put_termcaps(t->clean);
	ft_putchar_fd(' ', 0);;
}

void clear_screen(t_term *t)
{
	put_termcaps(t->clear_screen);
}
