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
	el->text = ft_strdup(data);
	el->is_selected = selected;
	el->is_current = current;
	ftarray__push(array, el);
}
t_array *testing_array(void)
{
	t_el el;
	t_array *array = ftarray__init(10, sizeof(t_el));
	char buff[30];

	for (int i = 0; i < 100; ++i)
	{
		ft_bzero(buff, 30);
		sprintf(buff, "el_________%d", i);
		set_el(&el, buff, 0, 0, array);
	}
	if (array->length)
		((t_el *)ftarray__at(array, 0))->is_current = 1;
	return (array);
}

