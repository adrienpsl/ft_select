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

int get_min_size(t_array *array)
{
	int size;
	int length;
	t_el *el;

	size = 0;
	ftarray__set_start(array);
	while (NULL != (el = ftarray__next(array)))
	{
		length = ft_strlen(el->text);
		if (size < length)
			size = length;
	}
	return (size + 2);
}

bool is_good_index(int index, int nb_elements)
{
	if (index < 0)
		return (false);
	if (index < nb_elements)
		return (true);
	return (false);
}

bool get_window_size(t_window *w, int nb_elements, int size_el)
{
	static struct winsize size;

	if (-1 == ioctl(STDIN_FILENO, TIOCGWINSZ, &size))
		return (false);
	else
	{
		w->elem_by_line = size.ws_col / size_el;
		if (w->elem_by_line == 0)
			w->elem_by_line = nb_elements;
		w->nb_lines = (nb_elements / w->elem_by_line);
		if (w->nb_lines == 0)
			w->nb_lines = 1;
		w->is_enough = size.ws_row - w->nb_lines > 0 ? true: false;
		putchar('b');
		return (true);
	}
}
