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

t_sct *set_sct(t_sct *s)
{
	static t_sct *ptr;

	if (s == NULL)
		return (ptr);
	else
	{
		ptr = s;
		return (NULL);
	}
}

t_sct *get_sct(void)
{
	return (set_sct(NULL));
}

t_term *get_term(void)
{
	return (&get_sct()->term);
}

t_window *get_win(void)
{
	return (&get_sct()->window);
}

t_array *get_elements(void)
{
	return (get_sct()->elements);
}

int g_current(void)
{
	return (get_sct()->current);
}

int *set_current(void)
{
	return (&get_sct()->current);
}

int get_elements_length(void)
{
	return (get_elements()->length - 1);
}