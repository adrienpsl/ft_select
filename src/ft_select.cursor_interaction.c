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

void move_if_valid_new_index(int step_size)
{
	t_el *el;

	if (g_select.current + step_size == -1)
	    step_size = 0;
	if (is_good_index( g_select.current + step_size))
	{
		clear_screen();
		el = ftarray__at(g_select.elements, g_select.current);
		el->is_current = 0;
		el = ftarray__at(g_select.elements, g_select.current + step_size);
		el->is_current = 1;
		loop_and_print(g_select.elements);
		g_select.current += step_size;
	}
}

void space(void)
{
	t_el *el;

	el = ftarray__at(g_select.elements, g_select.current);
	el->is_selected = !el->is_selected;
	move_if_valid_new_index(+1);
}

void del(void)
{
//	get_window_size(&g_select.window, g_select.elements->length);
	ftarray__remove(g_select.elements, g_select.current);
	move_if_valid_new_index(-1);
}
