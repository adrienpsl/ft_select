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

# include <ft_select.h>
#include <termcap.h>

static int check_and_init()
{
	char *term_name;
	int ret;

	if (NULL == (term_name = getenv("TERM")))
	{
		ft_putstr_fd_nl("Specify a terminal type with 'TERM=<type>'.\n",
			STDERR_FILENO);
		return -1;
	}
	ret = tgetent(NULL, term_name);
	if (ret == -1)
	{
		ft_putstr_fd_nl("Could not access the termcap data base.\n",
			STDERR_FILENO);
		return (-1);
	}
	if (ret == 0)
	{
		ft_putstr_fd_nl("Terminal is not defined in termcap database "
						"(or too little information).\n", STDERR_FILENO);
		return (-1);
	}
	return (OK);
}

static int get_all_termcaps(t_term *t)
{
	if (NULL == (t->move = tgetstr("cm", NULL))
		|| NULL == (t->underline = tgetstr("us", NULL))
		|| NULL == (t->reverse = tgetstr("mr", NULL))
		|| NULL == (t->clean = tgetstr("me", NULL))
		|| NULL == (t->clear_screen = tgetstr("cl", NULL)))
		return (-1);
	return (OK);
}

int load_term_caps(t_term *t)
{
	if (OK != check_and_init()
		|| OK != get_all_termcaps(t))
		return (-1);
	return (OK);
}