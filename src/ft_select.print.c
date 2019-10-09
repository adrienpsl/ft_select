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

void loop_and_print(t_array *array)
{
	t_el *el;

	array->i = 0;
	while (NULL != (el = ftarray__next(array)))
	{
		if (el->is_current && el->is_selected)
			print_in_underline_reverse(el->text);
		else if (el->is_current)
			print_in_underline(el->text);
		if (el->is_selected)
			print_in_reverse(el->text);
		else
			ft_printf("%s ", el->text);
	}
}
