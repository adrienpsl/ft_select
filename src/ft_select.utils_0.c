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

void		inverse_current(int index)
{
	t_el *el;
	el = ftarray__at(get_elements(), index);
	el->is_current = !el->is_current;
}

int			get_min_size(t_array *array)
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

bool		is_good_index(int index, int nb_elements)
{
	if (index >= 0 && index < nb_elements)
		return (true);
	return (false);
}

