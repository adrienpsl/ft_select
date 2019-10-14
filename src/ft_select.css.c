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

int print_underline(char *text)
{
	tputs(" ", 1, putchar_0);
	tputs(RED, 1, putchar_0);
	tputs(get_term()->underline, 1, putchar_0);
	tputs(text, 1, putchar_0);
	tputs(get_term()->reset, 1, putchar_0);
	tputs(" ", 1, putchar_0);
	return (1);
}

int print_reverse(char *text)
{
	tputs(" ", 1, putchar_0);
	print_color_file(text);
	tputs(get_term()->reverse, 1, putchar_0);
	tputs(text, 1, putchar_0);
	tputs(get_term()->reset, 1, putchar_0);
	tputs(" ", 1, putchar_0);
	return (1);
}

int print_underline_reverse(char *text)
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

int print_normal(char *text)
{
	tputs(" ", 1, putchar_0);
	print_color_file(text);
	tputs(text, 1, putchar_0);
	tputs(" ", 1, putchar_0);
	return (1);
}

int clear_screen(void)
{

	tputs(tgetstr("cl", NULL), 1, putchar_0);
	return (1);
}
