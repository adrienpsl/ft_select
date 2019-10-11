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
	ft_dprintf(0, termcaps);
	//	if (ERR == tputs(termcaps, 1, putchar_on_fd_0))
	//	{
	//		ft_dprintf(2, FT_SELECT_NAME"can't print the termcaps");
	//		return (false);
	//	}
	return (true);
}

void print_in_underline(char *text)
{
	ft_dprintf(FT_FD_OUT, " %s" "%s" "%s ",
		get_term()->underline,
		text,
		get_term()->reset);
}

void print_in_reverse(char *text)
{
	ft_dprintf(FT_FD_OUT, " %s" "%s" "%s ",
		get_term()->reverse,
		text,
		get_term()->reset);
}

void print_in_underline_reverse(char *text)
{
	ft_dprintf(FT_FD_OUT, " %s%s" "%s" "%s ",
		get_term()->reverse, get_term()->underline,
		text,
		get_term()->reset);
}

void clear_screen(void)
{
	ft_dprintf(FT_FD_OUT, get_term()->clear_screen);
}
