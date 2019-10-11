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

	(void)nb;
	s = get_sct(NULL);
	quit_binary(s->elements, &s->termios);
}

static void put_in_foreground(int nb)
{
	t_sct *s;

	(void)nb;
	s = get_sct(NULL);
	catch_all_signal();
	if (OK != set_canonical(&s->termios))
	{
		quit_binary(s->elements, &s->termios);
	}
	ft_printf("toto \n");
	start_display(s);
}

static void put_in_background(int nb)
{
	t_sct *s;

	(void)nb;
	s = get_sct(NULL);
	unset_canonical_mode(&s->termios);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
}

static void changing_window(int nb)
{
	t_sct *s;

	(void)nb;
	s = get_sct(NULL);
	get_window_size(&s->window, s->elements->length,
		s->size_el);
	clear_screen();
	if (s->window.is_enough == false)
		ft_dprintf(0, "The window is too little dude ! line lack : %d",
			s->window.is_enough);
//	else
//		print_data(s->elements, &s->term, &s->window,
//			s->size_el);
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