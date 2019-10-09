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

// je set a 0 mon cursor,
// je print a chaque fois plus un
int put_cursor_next(int *col, int *line);
int put_cursor_next(int *col, int *line)
{

	char *caps = tgetstr("cm", NULL);
	tputs(tgoto(caps, *line, *col), 1, ft_putchar);
	*line += g_select.min_size;
	if (*line + g_select.min_size >= g_select.size.ws_col)
	{
		*line = 0;
		*col += 1;
	}
	return (1);
}

// if left > less space ?
void loop_and_print(t_array *array)
{
	t_el *el;
	int col = 0;
	int line = 0;

	array->i = 0;
	while (NULL != (el = ftarray__next(array)))
	{
		put_cursor_next(&col, &line);
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
