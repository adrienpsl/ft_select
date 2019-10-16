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
#include <termcap.h>

static int	check_and_init(void)
{
	char	*term_name;
	int		ret;

	if (NULL == (term_name = getenv("TERM")))
	{
		ft_dprintf(0, "Specify a terminal type with 'TERM=<type>'.\n");
		return (-1);
	}
	ret = tgetent(NULL, term_name);
	if (ret == -1)
	{
		ft_dprintf(0, "Could not access the termcap data base.\n");
		return (-1);
	}
	if (ret == 0)
	{
		ft_dprintf(0, "Terminal type '%s' is not defined in termcap database "
				"(or too little information).\n", term_name);
		return (-1);
	}
	return (OK);
}

static int	get_all_termcaps(t_term *t)
{
	if (NULL == (t->move = tgetstr("cm", NULL))
		|| NULL == (t->underline = tgetstr("us", NULL))
		|| NULL == (t->reverse = tgetstr("mr", NULL))
		|| NULL == (t->reset = tgetstr("me", NULL))
		|| NULL == (t->hide_cursor = tgetstr("vi", NULL))
		|| NULL == (t->show_cursor = tgetstr("ve", NULL))
		|| NULL == (t->delete_line = tgetstr("dl", NULL))
		|| NULL == (t->clear_screen = tgetstr("cl", NULL))
		|| NULL == (t->clear_screen = tgetstr("cl", NULL)))
		return (-1);
	return (OK);
}

int			load_termcaps(t_term *t)
{
	if (OK != check_and_init()
		|| OK != get_all_termcaps(t))
		return (-1);
	return (OK);
}
