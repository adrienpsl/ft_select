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

int print_in_underline(char *text)
{
	ft_dprintf(FT_FD_OUT, " %s" "%s" "%s ",
		get_term()->underline,
		text,
		get_term()->reset);
	return (1);
}

int print_in_reverse(char *text)
{
	ft_dprintf(FT_FD_OUT, " %s" "%s" "%s ",
		get_term()->reverse,
		text,
		get_term()->reset);
	return (1);
}

int print_in_underline_reverse(char *text)
{
	ft_dprintf(FT_FD_OUT, " %s%s" "%s" "%s ",
		get_term()->reverse, get_term()->underline,
		text,
		get_term()->reset);
	return (1);
}

int clear_screen(void)
{
//	ft_dprintf(FT_FD_OUT, get_term()->clear_screen);
//	;
	fputs(tgetstr("cl", NULL), stdout);
	return (1);
}
