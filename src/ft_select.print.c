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

static int placing_cursor(t_pos *pos)
{
	char *goto_term;

	if (NULL == (goto_term = tgoto(
		get_term()->move, pos->x * get_sct()->size_el, pos->y)))
		return (-1);
	tputs(goto_term, 1, putchar_0);
	pos->x += 1;
	if (pos->x >= get_sct()->window.line_wide)
	{
		pos->x = 0;
		pos->y += 1;
	}
	return (1);
}

static void loop_on_elements(t_array *els, t_pos *pos)
{
	static t_el *el;
	t_sct *s = get_sct();
	int i =  get_win()->current_step;

	els->i = 0;
	s->max_y = 4;
	while (i < s->window.capacity + get_win()->current_step
		&& i < els->length)
	{
		el = ftarray__at(els, i);
		placing_cursor(pos);
		if ((el->is_current && el->is_selected)
			&& print_in_underline_reverse(el->text));
		else if (el->is_current
				 && print_in_underline(el->text));
		else if (el->is_selected
				 && print_in_reverse(el->text));
		else
		{
			tputs(" ", 1, putchar_0);
			print_color_file(el->text);
			tputs(el->text, 1, putchar_0);
			tputs(" ", 1, putchar_0);
		}
		i++;
	}
}

void print_list(t_array *els)
{
	static t_pos pos;

	pos.x = 0;
	pos.y = 0;
	clear_screen();
		if (get_win()->is_enough == false)
		{
			ft_dprintf(0, "The window is too little dude !");
			return ;
		}
	loop_on_elements(els, &pos);
}
