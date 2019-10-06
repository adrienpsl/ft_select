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
		ft_printf("Specify a terminal type with 'TERM=<type>'.\n");
		return -1;
	}
	ret = tgetent(NULL, term_name);
	if (ret == -1)
	{
		ft_printf("Could not access the termcap data base.\n");
		return (-1);
	}
	if (ret == 0)
	{
		ft_printf("Terminal type '%s' is not defined in termcap database "
				  "(or too little information).\n", term_name);
		return (-1);
	}
	return (OK);
}

int load_term_caps(void)
{
	if (OK != check_and_init())
		return (-1);
	return (OK);
}