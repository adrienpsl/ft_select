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

// here I can se helper 

static int need_display_down(int step)
{
	return (step > 0 &&
			step + get_sct()->current >=
			get_win()->current_step + get_win()->capacity);
}

static int need_display_up(int step)
{
	return (step <= 0 &&
			step + get_sct()->current <= get_win()->current_step
			&& step + get_sct()->current > 0);
}

static void move_next(int step)
{
	t_el *current;
	t_el *new;
	t_sct *s;

	s = get_sct();

	if (true == need_display_down(step))
		get_win()->current_step += get_win()->capacity;
	else if (true == need_display_up(step))
		get_win()->current_step -= get_win()->capacity;
	//	else if (step)
	//	    ;


	current = ftarray__at(s->elements, s->current);
	current->is_current = 0;
	new = ftarray__at(s->elements, s->current + step);
	new->is_current = 1;
	s->current += step;
}

static int go_last()
{
	return (get_sct()->elements->length - 1);
}

static int go_first()
{
	return (-go_last());
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
	ftarray__remove(s->elements, s->current);
	print_list(s->elements);
	move_selector(-1, s);
	return (1);
}

/*
**	dispatch at the good function according to the user input
*/

int dispatch_user_key(int *buffer, t_sct *s)
{
	K_UP == *buffer && move_selector(-s->window.line_wide, s);
	K_DOWN == *buffer && move_selector(s->window.line_wide, s);
	K_LEFT == *buffer && move_selector(-1, s);
	K_RIGHT == *buffer && move_selector(+1, s);
	K_SPACE == *buffer && space(s);
	((K_DEL == *buffer || K_BACKSPACE == *buffer) && del(s));
	if (K_ENTER == *buffer)
		return (1);
	else if (K_ESCAPE == *buffer)
		return (-1);
	else if (s->elements->length == 0)
		return (-1);
	else
		return (OK);
}
