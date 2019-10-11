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


static void dispatch_between_order(char *buffer, t_sct *s)
{
	if (OK == ft_strcmp(FT_UP, buffer))
		move_if_valid_new_index(-s->window.elem_by_line, s);
	if (OK == ft_strcmp(FT_DOWN, buffer))
		move_if_valid_new_index(s->window.elem_by_line, s);
	if (OK == ft_strcmp(FT_LEFT, buffer))
		move_if_valid_new_index(-1, s);
	if (OK == ft_strcmp(FT_RIGHT, buffer))
		move_if_valid_new_index(+1, s);
	if (OK == ft_strcmp(" ", buffer))
		space(s);
	if (OK == ft_strcmp(FT_DEL, buffer)
		|| OK == ft_strcmp(FT_BACKSPACE, buffer))
		del(s);
}

int ms__get_line(t_sct *s)
{
	static char buffer[5] = { 0 };

	ft_bzero(&buffer, 5);
	while (OK != ft_strcmp(buffer, "\n"))
	{
		ft_bzero(&buffer, 5);
		if (read(0, buffer, 4) < 0)
			return (-1);
		dispatch_between_order(buffer, s);
	}
	return (OK);
}
