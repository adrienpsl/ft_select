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

static int	need_display_down(int step)
{
	return (step > 0 &&
			step + get_sct()->current >=
			get_win()->current_step + get_win()->capacity);
}

static int	need_display_up(int step)
{
	return (step <= 0 &&
			step + get_sct()->current < get_win()->current_step
			&& step + get_sct()->current > 0);
}

static int	need_display_upper(int step)
{
	return (step == go_first());
}

static int	need_display_downer(int step)
{
	return (step == go_last());
}

void		move_display(int step)
{
	if (get_win()->capacity >= get_elements_length())
		return ;
	if (true == need_display_upper(step))
		get_win()->current_step = 0;
	else if (true == need_display_downer(step))
		get_win()->current_step = get_win()->last_step;
	else if (true == need_display_down(step))
		get_win()->current_step += get_win()->capacity;
	else if (true == need_display_up(step))
		get_win()->current_step -= get_win()->capacity;
}
