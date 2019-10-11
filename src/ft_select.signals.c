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
}

// TODO : handle error
static void background(int nb)
{
	(void)nb;
	unset_canonical_mode(&g_select.termios);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
}

static void changing_window(int nb)
{
	(void)nb;
	get_window_size(&g_select.window, g_select.elements->length);
	clear_screen(&g_select.term);
	loop_and_print(g_select.elements, &g_select.term, &g_select.window);
}

void catch_all_signal(void)
{
	(void)quit;
	(void)wake_up;
	(void)background;
	//	signal(SIGINT, quit);
	//	signal(SIGHUP, quit);
	//	signal(SIGQUIT, quit);
	// kill
	//	signal(SIGABRT, quit);
	//	signal(SIGBUS, quit);
	//	signal(SIGSEGV, quit);

	signal(SIGWINCH, changing_window);

	//	signal(SIGTSTP, background);
	//	signal(SIGHUP, wake_up);
}