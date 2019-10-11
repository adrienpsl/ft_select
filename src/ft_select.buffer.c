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

/*
**	dispatch at the good function according to the user input
*/

static int dispatch_user_key(char *buffer, t_sct *s)
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

/*
**	as we are in raw mode, I have to handle the line buffer by myself
*/

int catch_and_treat_user_input(t_sct *s)
{
	static char buffer[5] = { 0 };
	int ret;

	ft_bzero(&buffer, 5);
	while (OK != ft_strcmp(buffer, "\n"))
	{
		ft_bzero(&buffer, 5);
		if (read(0, buffer, 4) < 0)
			return (-1);
		if (OK != (ret = dispatch_user_key(buffer, s)))
			return (ret);
	}
	return (OK);
}
