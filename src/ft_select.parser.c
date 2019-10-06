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

static int check_and_init(int ac, t_sct *select)
{
	ft_bzero(select, sizeof(t_sct));
	if (ac == 1)
		return (1);
	if (NULL == (select->elememens = ftarray__init(ac, sizeof(t_sct))))
		return (-1);
	ft_bzero(&g_signal, sizeof(g_signal));
	select->signal = &g_signal;
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
		el.data = av[i];
		ftarray__push(select->elememens, &el);
		i += 1;
	}
}

int init_ftselect(int ac, char **av, t_sct *select)
{
	if (OK != check_and_init(ac, select))
		return (-1);
	copy_argv_in_elements(ac, av, select);
	select->min_size = get_min_size(select->elememens);
	return (OK);
}
