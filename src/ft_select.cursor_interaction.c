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

static void move_next(int step)
{
	t_el *current;
	t_el *new;
	t_sct *s;

	s = get_sct(NULL);
	current = ftarray__at(s->elements, s->current);
	current->is_current = 0;
	new = ftarray__at(s->elements, s->current + step);
	new->is_current = 1;
	s->current += step;
}

int move_selector(int step_size, t_sct *s)
{
	if (step_size == -1
		&& s->current == 0)
		move_next(s->elements->length - 1);
	else if (s->current + step_size < 0)
		return (1);
	else if (step_size == 1
			 && s->current + step_size == s->elements->length)
		move_next(-(s->elements->length - 1));
	else if (true ==
			 is_good_index(s->current + step_size, s->elements->length))
		move_next(step_size);
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

/*
**	dispatch at the good function according to the user input
*/

int dispatch_user_key(char *buffer, t_sct *s)
{
	ft_streq(FT_UP, buffer) && move_selector(-s->window.line_wide, s);
	ft_streq(FT_DOWN, buffer) && move_selector(s->window.line_wide, s);
	ft_streq(FT_LEFT, buffer) && move_selector(-1, s);
	ft_streq(FT_RIGHT, buffer) && move_selector(+1, s);
	ft_streq(FT_SPACE, buffer) && space(s);
	((ft_streq(FT_DEL, buffer) || ft_streq(FT_BACKSPACE, buffer)) && del(s));
	if (ft_streq(FT_ENTER, buffer))
		return (1);
	else if (ft_streq(FT_ECHAP, buffer))
		return (-1);
	else if (s->elements->length == 0)
		return (-1);
	else
		return (OK);
}
