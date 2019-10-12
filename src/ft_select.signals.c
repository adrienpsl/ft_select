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

// to prenvent a bug or feature but a shit stuff.
static int g_is_foreground;

static void quit(int nb)
{
	t_sct *s;

	s = get_sct(NULL);
	quit_binary(s->elements, &s->termios);
	(void)nb;
}

static void put_in_background(int nb)
{
	unset_canonical_mode(&get_sct(NULL)->termios);
	signal(SIGTSTP, SIG_DFL);
	ioctl(1, TIOCSTI, "\x1A");
	g_is_foreground = true;
	(void)nb;
}

static void put_in_foreground(int nb)
{
	t_sct *s;

	if (g_is_foreground == true)
	{
		s = get_sct(NULL);
		signal(SIGTSTP, put_in_background);
		if (OK != set_canonical(&s->termios))
		{
			quit_binary(s->elements, &s->termios);
		}
			get_window_and_print(s);
		(void)nb;
		g_is_foreground = true;
	}
}

static void changing_window(int nb)
{
	(void)nb;
		get_window_and_print(get_sct(NULL));
}

void catch_all_signal(void)
{
	g_is_foreground = false;
	signal(SIGINT, quit);
	signal(SIGHUP, quit);
	signal(SIGQUIT, quit);
	signal(SIGABRT, quit);
	signal(SIGBUS, quit);
	signal(SIGSEGV, quit);
	signal(SIGWINCH, changing_window);
	signal(SIGTSTP, put_in_background);
	signal(SIGCONT, put_in_foreground);
}
