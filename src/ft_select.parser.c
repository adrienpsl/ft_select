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

static int init_structure(int ac, t_sct *select)
{
	ft_bzero(select, sizeof(t_sct));
	if (NULL == (select->elements = ftarray__init(ac, sizeof(t_sct))))
		return (-1);
	return (OK);
}

static void copy_argv_in_elements(int ac, char **av, t_sct *select)
{
	t_el el;
	int i;

	i = 1;
	while (i < ac)
	{
		ft_bzero(&el, sizeof(t_el));
		el.text = av[i];
		ftarray__push(select->elements, &el);
		i += 1;
	}
}

int init_ftselect(int ac, char **av, t_sct *select)
{
	if (OK != init_structure(ac, select))
		return (-1);
	copy_argv_in_elements(ac, av, select);
	select->size_el = get_min_size(select->elements);
	return (OK);
}
