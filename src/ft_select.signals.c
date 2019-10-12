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
	t_sct *s;

	s = get_sct(NULL);
	quit_binary(s->elements, &s->termios);
	(void)nb;
}

static void put_in_foreground(int nb)
{
	// here set a protection to that.
	t_sct *s;

	s = get_sct(NULL);
	catch_all_signal();
	ft_dprintf(0, "fore");
	if (OK != set_canonical(&s->termios))
	{
		quit_binary(s->elements, &s->termios);
	}
//	get_window_and_print(s);
	(void)nb;
}

static void put_in_background(int nb)
{
	ft_dprintf(0, "back");
	unset_canonical_mode(&get_sct(NULL)->termios);
	signal(SIGTSTP, SIG_DFL);
	ioctl(1, TIOCSTI, "\x1A");
	(void)nb;
}

static void changing_window(int nb)
{
	(void)nb;
//	get_window_and_print(get_sct(NULL));
ft_dprintf(0, "change");
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
	signal(SIGTSTP, put_in_background);
	signal(SIGCONT, put_in_foreground);
}
