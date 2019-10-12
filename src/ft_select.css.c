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
	tputs(" ", 1, putchar_0);
	tputs(RED, 1, putchar_0);
	tputs(get_term()->underline, 1, putchar_0);
	tputs(text, 1, putchar_0);
	tputs(get_term()->reset, 1, putchar_0);
	tputs(" ", 1, putchar_0);
	return (1);
}

int print_in_reverse(char *text)
{
	tputs(" ", 1, putchar_0);
	tputs(get_term()->reverse, 1, putchar_0);
	tputs(text, 1, putchar_0);
	tputs(get_term()->reset, 1, putchar_0);
	tputs(" ", 1, putchar_0);
	return (1);
}

int print_in_underline_reverse(char *text)
{
	tputs(" ", 1, putchar_0);
	tputs(RED, 1, putchar_0);
	tputs(get_term()->reverse, 1, putchar_0);
	tputs(get_term()->underline, 1, putchar_0);
	tputs(text, 1, putchar_0);
	tputs(get_term()->reset, 1, putchar_0);
	tputs(" ", 1, putchar_0);
	return (1);
}

int clear_screen(void)
{
	int i = 0;
	tputs(tgoto(get_term()->move, 0, 0), 1, putchar_0);

	while (i < get_win()->nb_line)
	{
		tputs(tgetstr("dl", NULL), 1, putchar_0);
		i++;
	}
	return (1);
}
