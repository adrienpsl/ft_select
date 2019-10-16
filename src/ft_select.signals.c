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
#include <sys/ioctl.h>

static void		quit(int nb)
{
	t_sct *s;

	s = get_sct();
	quit_binary(s->elements, &s->termios);
	(void)nb;
}

static void		put_in_background(int nb)
{
	tputs(get_term()->show_cursor, 1, putchar_0);
	unset_canonical_mode(&get_sct()->termios);
	clear_screen();
	signal(SIGTSTP, SIG_DFL);
	ioctl(1, TIOCSTI, "\x1A");
	get_sct()->is_foreground = true;
	(void)nb;
}

static void		put_in_foreground(int nb)
{
	t_sct *s;

	if (get_sct()->is_foreground == true)
	{
		s = get_sct();
		signal(SIGTSTP, put_in_background);
		if (OK != set_canonical(&s->termios))
			quit_binary(s->elements, &s->termios);
		get_window_and_print(s);
		get_sct()->is_foreground = true;
		tputs(get_term()->hide_cursor, 1, putchar_0);
	}
	(void)nb;
}

static void		changing_window(int nb)
{
	(void)nb;
	inverse_current(g_current());
	get_sct()->current = 0;
	inverse_current(g_current());
	get_sct()->window.current_step = 0;
	get_window_and_print(get_sct());
}

int				handle_all_signal(void)
{
	get_sct()->is_foreground = false;
	signal(SIGHUP, quit);
	signal(SIGINT, quit);
	signal(SIGQUIT, quit);
	signal(SIGILL, quit);
	signal(SIGABRT, quit);
	signal(SIGFPE, quit);
	signal(SIGPIPE, quit);
	signal(SIGALRM, quit);
	signal(SIGTERM, quit);
	signal(SIGBUS, quit);
	signal(SIGSEGV, quit);
	signal(SIGWINCH, changing_window);
	signal(SIGTSTP, put_in_background);
	signal(SIGCONT, put_in_foreground);
	return (OK);
}
