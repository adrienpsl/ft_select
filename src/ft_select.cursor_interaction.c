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

static void move_cursor(int step_size, t_sct *s)
{
	t_el *el;

	el = ftarray__at(s->elements, s->current);
	el->is_current = 0;
	el = ftarray__at(s->elements, s->current + step_size);
	el->is_current = 1;
	s->current += step_size;
}

static void start_cursor(t_sct *s)
{
	t_el *el;

	el = ftarray__at(s->elements, s->elements->length - 1);
	el->is_current = 0;
	el = ftarray__at(s->elements, 0);
	el->is_current = 1;
	s->current = 0;
}

static void end_cursor(t_sct *s)
{
	t_el *el;

	el = ftarray__at(s->elements, s->elements->length - 1);
	el->is_current = 1;
	el = ftarray__at(s->elements, 0);
	el->is_current = 0;
	s->current = s->elements->length;
}

int move_selector(int step_size, t_sct *s)
{
	if (step_size == -1 && s->current == 0)
		end_cursor(s);
	else if (s->current + step_size < 0)
		step_size = 0;
	if (step_size == 1 && s->current + step_size == s->elements->length)
		start_cursor(s);
	else if (true == is_good_index(s->current + step_size, s->elements->length))
		move_cursor(step_size, s);
	print_data(s->elements, &s->term, &s->window, s->size_el);
	return (1);
}

int space(t_sct *s)
{
	t_el *el;

	el = ftarray__at(s->elements, s->current);
	el->is_selected = !el->is_selected;
	print_data(s->elements, &s->term, &s->window, s->size_el);
	move_selector(+1, s);
	return (1);
}

int del(t_sct *s)
{
	ftarray__remove(s->elements, s->current);
	print_data(s->elements, &s->term, &s->window, s->size_el);
	move_selector(-1, s);
	return (1);
}
