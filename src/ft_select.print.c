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

static int put_cursor_next(t_pos *pos)
{
	tputs(tgoto(g_select.term.move, pos->x * g_select.size_el, pos->y),
		1, ft_putchar);
	pos->x += 1;
	if (pos->x >= g_select.window.elem_by_line)
	{
		pos->x = 0;
		pos->y += 1;
	}
	return (1);
}

void loop_and_print(t_array *els, t_term *t, t_window *w)
{
	t_el *el;
	t_pos pos;

	pos.x = 0;
	pos.y = 0;
	(void)w;
	clear_screen(t);
	els->i = 0;
	while (NULL != (el = ftarray__next(els)))
	{
		put_cursor_next(&pos);
		if (el->is_current && el->is_selected)
			print_in_underline_reverse(el->text, t);
		else if (el->is_current)
			print_in_underline(el->text, t);
		else if (el->is_selected)
			print_in_reverse(el->text, t);
		else
			ft_printf(" %s ", el->text);
	}
	//	ft_printf("%d-- current :%d %d", array->length, g_select.current, is_good_index(g_select.current));
	ft_printf("-- %d", g_select.current);
}
