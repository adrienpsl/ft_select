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

static void	go_start_last_line()
{
	tputs(tgoto(get_term()->move, 0, get_win()->winsize.ws_row), 1, putchar_0);
	tputs(get_term()->delete_line, 1, putchar_0);
}

static void	free_buffer()
{
	tputs(get_term()->delete_line, 1, putchar_0);
	tputs(get_term()->hide_cursor, 1, putchar_0);
	ftarray__func(get_sct()->elements, select_all_match, NULL);
	print_list(get_sct()->elements);
	ftstr__free(set_buffer());
}

static void	buffering_and_display(char *buffer)
{
	int length;

	go_start_last_line();
	length = ft_strlen(get_buffer()) - 1;
	if (buffer[0] == K_BACKSPACE)
	{
		if (length < 0)
			length = 0;
		get_buffer()[length] = 0;
	}
	else if (length + 2 < get_win()->winsize.ws_col - 2)
		ft_pstrjoin(get_buffer(), buffer, 1, set_buffer());
	tputs(get_term()->delete_line, 1, putchar_0);
	tputs(get_buffer(), 1, putchar_0);
}

static void	init_buffer()
{
	go_start_last_line();
	tputs(get_term()->show_cursor, 1, putchar_0);
	*set_buffer() = ft_strdup("");
}

void		search_mode(long *buffer)
{
	if (*buffer == '$' && NULL != get_buffer())
		free_buffer();
	else if (get_buffer() == NULL)
		init_buffer();
	else
		buffering_and_display((char *)buffer);
}
