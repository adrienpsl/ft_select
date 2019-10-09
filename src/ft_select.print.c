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
	printf(" \n");
	
	el = ftarray__at(array, 0);
//	ft_printf("%s \n", *el->data);
//	ft_printf("%d \n", el->is_selected);
//	el = ftarray__at(array, 1);
//	ft_printf("%s \n", *el->data);
	while (NULL != (el = ftarray__next(array)))
	{
//		printf("%p\n", *el->data);
//		printf("%s\n", *el->data);
//		printf("%p\n", el->data);
//		printf("%s\n", *((char**)el->data));
//		printf("%d\n", el->is_selected);
//		printf("%s\n", *(el->data));
		//		if (el->is_current && el->is_selected)
//			print_in_underline_reverse(el->data);
//		else if (el->is_current)
//			print_in_underline(el->data);
//		if (el->is_selected)
//			print_in_reverse(el->data);
//		else
//			ft_printf(el->data);
	}
}

