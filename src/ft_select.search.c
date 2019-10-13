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

static void go_last_line()
{
	tputs(tgoto(get_term()->move, 0, get_win()->window_y), 1, putchar_0);
}

static void free_buffer()
{
	tputs(get_buffer(), 1, putchar_0);
	ftstr__free(set_buffer());
	tputs(tgetstr("dl", NULL), 1, putchar_0);
	go_last_line();
}

static void init_buffer()
{
	*set_buffer() = ft_strdup("");
}

static void add_to_buffer_and_print(char *buffer)
{
	ft_pstrjoin(get_buffer(), buffer, 1, set_buffer());
	tputs(get_buffer(), 1, putchar_0);
}

void handle_buffer(long *buffer)
{
	if (*buffer == '$' && NULL != get_buffer())
		free_buffer();
	else if (get_buffer() == NULL)
		init_buffer();
	else
		add_to_buffer_and_print((char *)buffer);
}
