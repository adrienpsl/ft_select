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

void get_position(t_pos *pos, int index, t_window *w)
{
	pos->x = index % w->elem_by_line;
	pos->y = (index / w->elem_by_line);
}

bool is_good_index(t_window *w, int index)
{
	t_pos pos;

	get_position(&pos, index, w);
	//	printf("%d %d %d %d", pos.x, pos.y, w->nb_lines, w->x_last_el);
	if (pos.y < 0 || pos.x < 0)
	    return (false);
	if (pos.y < w->nb_lines)
		return (true);
	if (pos.y == w->nb_lines
		&& pos.x < w->x_last_el)
		return (true);
	return (false);
}
