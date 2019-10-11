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

void move_if_valid_new_index(int step_size, t_sct *s)
{
	t_el *el;

	if (s->current + step_size < 0)
		step_size = 0;
	if (true == is_good_index(s->current + step_size, s->elements->length))
	{
		el = ftarray__at(s->elements, s->current);
		el->is_current = 0;
		el = ftarray__at(s->elements, s->current + step_size);
		el->is_current = 1;
		s->current += step_size;
		print_data(s->elements, &s->term, &s->window, s->size_el);
	}
}

void space(t_sct *s)
{
	t_el *el;

	el = ftarray__at(s->elements, s->current);
	el->is_selected = !el->is_selected;
	print_data(s->elements, &s->term, &s->window, s->size_el);
	move_if_valid_new_index(+1, s);
}

void del(t_sct *s)
{
	ftarray__remove(s->elements, s->current);
	print_data(s->elements, &s->term, &s->window, s->size_el);
	move_if_valid_new_index(-1, s);
}
