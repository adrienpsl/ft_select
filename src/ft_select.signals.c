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
#include <sys/ioctl.h>

static void quit(int nb)
{
	(void)nb;
	ft_printf(FT_SELECT_NAME"please quit correctly that program to allow it"
			  "clean the terminal after it\n");
}

static void wake_up(int nb)
{
	(void)nb;
	catch_all_signal();
	start_display(g_select);
}

static void background(int nb)
{
	(void)nb;
	unset_canonical_mode(&g_select->termios);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
}

static void changing_window(int nb)
{
	(void)nb;
	get_window_size(&g_select->window, g_select->elements->length,
		g_select->size_el);
	clear_screen(&g_select->term);
	if (g_select->window.is_enough == false)
		ft_printf("The window is too little dude ! line lack : %d",
			g_select->window.is_enough);
	else
		print_data(g_select->elements, &g_select->term, &g_select->window,
			g_select->size_el);
}

void catch_all_signal(void)
{
	signal(SIGINT, quit);
	signal(SIGHUP, quit);
	signal(SIGQUIT, quit);
	signal(SIGABRT, quit);
	signal(SIGBUS, quit);
	signal(SIGSEGV, quit);
	signal(SIGWINCH, changing_window);
	signal(SIGTSTP, background);
	signal(SIGHUP, wake_up);
}