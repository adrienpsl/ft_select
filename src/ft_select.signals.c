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

static void quit(int nb)
{
	(void)nb;
	ft_printf(FT_SELECT_NAME"please quit correctly that program to allow it"
			  "clean the terminal after it");
}

static void wake_up(int nb)
{
	(void)nb;
	catch_all_signal();
}

static void background(int nb)
{
	(void)nb;
	catch_all_signal();
}


static void changing_window(int nb)
{
	(void)nb;
}

void catch_all_signal(void)
{
	signal(SIGINT, quit);
	signal(SIGHUP, quit);
	signal(SIGQUIT, quit);
	// kill
	signal(SIGABRT, quit);
	signal(SIGBUS, quit);
	signal(SIGSEGV, quit);

	signal(SIGWINCH, changing_window);

	signal(SIGTSTP, background);
	signal(SIGHUP, wake_up);
}