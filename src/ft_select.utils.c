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

int get_min_size(t_array *array)
{
	int size;
	int length;
	t_el *el;

	size = 0;
	ftarray__set_start(array);
	while (NULL != (el = ftarray__next(array)))
	{
		length = ft_strlen(el->text);
		if (size < length)
			size = length;
	}
	return (size + 2);
}

bool is_good_index(int index, int nb_elements)
{
	if (index >= 0 && index < nb_elements)
		return (true);
	return (false);
}

// I have to stock the data, to keep element in place
bool get_window_size(t_window *w, int nb_elements, int size_el)
{
	static struct winsize size;

	if (-1 == ioctl(STDIN_FILENO, TIOCGWINSZ, &size))
		return (false);
	w->line_wide = size.ws_col / size_el;
	if (w->line_wide == 0)
		w->line_wide = nb_elements;
	w->nb_line = (nb_elements / w->line_wide);
	if (w->nb_line == 0)
		w->nb_line = 1;
	w->is_enough = size.ws_row - w->nb_line > 0 ? true : false;
	return (true);
}

void quit_binary(t_array *elements, struct termios *backup)
{
	ftarray__free(&elements);
	if (backup->c_cc[VMIN])
		unset_canonical_mode(backup);
	exit(EXIT_SUCCESS);
}

void start_display(t_sct *s)
{
	clear_screen();
	get_window_size(&s->window, s->elements->length, s->size_el);
	print_data(s->elements, &s->term, &s->window, s->size_el);
}

int putchar_on_fd_0(int a)
{
	write(0, &a, 1);
	return (0);
}
