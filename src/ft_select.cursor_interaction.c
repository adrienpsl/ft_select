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

int go_last(void)
{
	return (get_elements_length());
}

int go_first(void)
{
	return (-go_last());
}

static void move_next(int step_size)
{
	t_el *current;
	t_el *new;

	move_display(step_size);
	current = ftarray__at(get_elements(), g_current());
	current->is_current = 0;
	new = ftarray__at(get_elements(), g_current() + step_size);
	new->is_current = 1;
	*set_current() += step_size;
}

int move_selector(int step_size, t_sct *s)
{
	if (step_size == -1
		&& s->current == 0)
		move_next(go_last());
	else if (s->current + step_size < 0)
		return (1);
	else if (step_size == 1
			 && s->current + step_size == s->elements->length)
		move_next(go_first());
	else if (true ==
			 is_good_index(s->current + step_size, s->elements->length))
		move_next(step_size);
	print_list(s->elements);
	return (1);
}

int space(t_sct *s)
{
	t_el *el;

	el = ftarray__at(s->elements, s->current);
	el->is_selected = !el->is_selected;
	print_list(s->elements);
	move_selector(+1, s);
	return (1);
}

int del(t_sct *s)
{
	int step = s->current == s->elements->length - 1 ? -1 : 0;
	ftarray__remove(s->elements, s->current);
	print_list(s->elements);
	move_selector(step, s);
	return (1);
}

/*
**	dispatch at the good function according to the user input
*/

int dispatch_user_key(int *buffer, t_sct *s)
{
	K_UP == *buffer && move_selector(get_win()->line_wide * -1, s);
	K_DOWN == *buffer && move_selector(get_win()->line_wide, s);
	K_LEFT == *buffer && move_selector(-1, s);
	K_RIGHT == *buffer && move_selector(+1, s);
	K_SPACE == *buffer && space(s);
	((K_DEL == *buffer || K_BACKSPACE == *buffer) && del(s));
	if (K_ENTER == *buffer)
		return (1);
	else if (K_ESCAPE == *buffer)
		return (-1);
	else if (get_elements_length() == 0)
		return (-1);
	else
		return (OK);
}
