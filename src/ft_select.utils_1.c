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

static int		is_screen_enough(t_window *w, int size_el)
{
	w->line_wide = w->winsize.ws_col / size_el;
	return (w->winsize.ws_row > 2 && w->line_wide);
}

bool			get_window_size(t_window *w, int nb_elements, int size_el)
{
	int row_minus_text_search_space;

	if (-1 == ioctl(STDIN_FILENO, TIOCGWINSZ, &w->winsize))
		return (false);
	if (false == (w->is_enough = is_screen_enough(w, size_el)))
		return (-1);
	row_minus_text_search_space = w->winsize.ws_row - 2;
	w->nb_line = (nb_elements / row_minus_text_search_space);
	w->capacity = w->line_wide * row_minus_text_search_space;
	w->current_step = 0;
	w->last_step = ((nb_elements / w->capacity) - 1) * w->capacity;
	return (true);
}

void			quit_binary(t_array *elements, struct termios *backup)
{
	ftarray__free(&elements);
	clear_screen();
	if (backup->c_cc[VMIN])
		unset_canonical_mode(backup);
	exit(EXIT_SUCCESS);
}

void			get_window_and_print(t_sct *s)
{
	get_window_size(&s->window, s->elements->length, s->size_el);
	print_list(s->elements);
}

int				putchar_0(int c)
{
	write(FT_FD_OUT, &c, 1);
	return (OK);
}