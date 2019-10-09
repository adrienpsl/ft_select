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


void set_el(t_el *el, char *data, int selected, int current, t_array *array)
{
	ft_bzero(el, sizeof(t_el));
	el->text = data;
	el->is_selected = selected;
	el->is_current = current;
	ftarray__push(array, el);
}

t_array *testing_array(void)
{
	t_el el;
	t_array *array = ftarray__init(10, sizeof(t_el));

	set_el(&el, "el_1", 1, 0, array);
	set_el(&el, "el_20", 0, 0, array);
	set_el(&el, "el_3", 1, 0, array);
	set_el(&el, "el_4", 1, 1, array);

	return (array);
}

