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

bool get_window_size(t_window *w, int nb_elements)
{
	static struct winsize size;

	if (-1 == ioctl(STDIN_FILENO, TIOCGWINSZ, &size))
		return (false);
	else
	{
		w->elem_by_line = size.ws_col / g_select.size_el;
		w->nb_lines = (nb_elements / w->elem_by_line);
		w->is_enough = (w->nb_lines * w->elem_by_line) / nb_elements;
		w->x_last_el = nb_elements % w->nb_lines;
		return (true);
	}
}
