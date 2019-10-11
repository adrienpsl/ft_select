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

#include <ft_select.h>

static int put_cursor_next(t_pos *pos, t_term *t, t_window *w, int size_el)
{
	char *goto_term;

	goto_term = tgoto(t->move, pos->x * size_el, pos->y);
	if (goto_term == NULL)
		return (-1);
	tputs(goto_term, 1, putchar_on_fd_0);
	pos->x += 1;
	if (pos->x >= w->line_wide)
	{
		pos->x = 0;
		pos->y += 1;
	}
	return (1);
}

void print_data(t_array *els, t_term *t, t_window *w, int size_el)
{
	t_el *el;
	t_pos pos;

	pos.x = 0;
	pos.y = 0;
	clear_screen();
	els->i = 0;
	while (NULL != (el = ftarray__next(els)))
	{
		put_cursor_next(&pos, t, w, size_el);
		if (el->is_current && el->is_selected)
			print_in_underline_reverse(el->text);
		else if (el->is_current)
			print_in_underline(el->text);
		else if (el->is_selected)
			print_in_reverse(el->text);
		else
			ft_dprintf(0, " %s ", el->text);
	}
}
