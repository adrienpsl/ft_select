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

static int is_arrow(char *buffer, t_sct *s)
{
	int ret;

	ret = 0;
	if (OK == ft_strcmp(FT_UP, buffer))
	{
		ret = move_if_valid_new_index(-s->window.elem_by_line, s);
	}
	else if (OK == ft_strcmp(FT_DOWN, buffer))
	{
		ret = move_if_valid_new_index(s->window.elem_by_line, s);
	}
	else if (OK == ft_strcmp(FT_LEFT, buffer))
	{
		ret = move_if_valid_new_index(-1, s);
	}
	else if (OK == ft_strcmp(FT_RIGHT, buffer))
	{
		ret = move_if_valid_new_index(+1, s);
	}
	return (ret);
}

static int dispatch_between_order(char *buffer, t_sct *s)
{
	if (1 == is_arrow(buffer, s))
	{
		return (OK);
	}
	else if (OK == ft_strcmp(" ", buffer))
	{
		space(s);
	}
	else if (OK == ft_strcmp(FT_DEL, buffer)
			 || OK == ft_strcmp(FT_BACKSPACE, buffer))
	{
		del(s);
	}
	if (OK == ft_strcmp(FT_ENTER, buffer))
	{
		return (1);
	}
	else if (OK == ft_strcmp(FT_ECHAP, buffer))
	{
		return (-1);
	}
	if (s->elements->length == 0)
	{
		return (-1);
	}
	return (OK);
}

/*
**	as we are in raw mode, I have to handle the line buffer by myself
*/

// I think here I've got a pb, I need to read on a new fd ?
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
		if (OK != (ret = dispatch_between_order(buffer, s)))
			return (ret);
	}
	return (OK);
}
