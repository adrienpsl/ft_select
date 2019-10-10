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

int put_cursor_next(int *col_index, int *line_index);
int put_cursor_next(int *col_index, int *line_index)
{
	tputs(tgoto(g_select.term.move, *col_index * g_select.size_el, *line_index),
		1, ft_putchar);
	*col_index += 1;
	if (*col_index >= g_select.window.elem_by_line)
	{
		*col_index = 0;
		*line_index += 1;
	}
	return (1);
}

// if left > less space ?
void loop_and_print(t_array *array)
{
	t_el *el;
	int col_index = 0;
	int line_index = 0;

	array->i = 0;
	while (NULL != (el = ftarray__next(array)))
	{
		put_cursor_next(&col_index, &line_index);
		if (el->is_current && el->is_selected)
			print_in_underline_reverse(el->text);
		else if (el->is_current)
			print_in_underline(el->text);
		else if (el->is_selected)
			print_in_reverse(el->text);
		else
			ft_printf(" %s ", el->text);
	}
}
