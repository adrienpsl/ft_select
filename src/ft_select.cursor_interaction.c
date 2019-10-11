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

// ici j'ai un pb avec mon current si je delete un seul element

void move_if_valid_new_index(int step_size)
{
	t_el *el;

	if (g_select.current + step_size < 0)
		step_size = 0;
	if (true == is_good_index(g_select.current + step_size))
	{
		el = ftarray__at(g_select.elements, g_select.current);
		el->is_current = 0;
		el = ftarray__at(g_select.elements, g_select.current + step_size);
		el->is_current = 1;
		g_select.current += step_size;
		loop_and_print(g_select.elements);
	}
}

void space(void)
{
	t_el *el;

	el = ftarray__at(g_select.elements, g_select.current);
	el->is_selected = !el->is_selected;
	loop_and_print(g_select.elements);
	move_if_valid_new_index(+1);
}

void del(void)
{
	ftarray__remove(g_select.elements, g_select.current);
	loop_and_print(g_select.elements);
	move_if_valid_new_index(-1);
}
