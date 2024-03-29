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

static void		print_value(void)
{
	t_array	*els;
	t_el	*el;
	int		first;

	first = 1;
	clear_screen();
	els = get_elements();
	els->i = 0;
	while (els->i < els->length)
	{
		el = ftarray__at(els, els->i);
		if (el->is_selected)
		{
			if (0 == first)
				ft_printf(" ");
			ft_printf("%s", el->text);
		}
		first = 0;
		els->i += 1;
	}
}

/*
**	will check if the binary got argument and if the shell is a good one
*/

static int		check(int ac)
{
	if (ac == 1)
		return (1);
	if (1 != isatty(STDIN_FILENO))
	{
		ft_dprintf(2, "That's not a term !");
		return (-1);
	}
	return (OK);
}

/*
**	copy char ** system argv ptr in my array.
**	Can fail if no memory.
*/

static int		get_argv(int ac, char **av, t_sct *select)
{
	t_el	el;
	int		i;

	if (NULL == (select->elements = ftarray__init(ac, sizeof(t_sct))))
		return (-1);
	i = 1;
	while (i < ac)
	{
		ft_bzero(&el, sizeof(t_el));
		el.text = av[i];
		ftarray__push(select->elements, &el);
		i += 1;
	}
	select->size_el = get_min_size(select->elements);
	((t_el*)ftarray__at(select->elements, 0))->is_current = 1;
	return (OK);
}

/*
**	that's the main function of the program
**	read, and buffering users input, three way are possible :
**		- we are in search mode, start with $ end with the same,
**		all the key write by the user are catch and at the end, all matchs
**		are selected.
**		- the key match one of them in the define file (ft_select.define.h)
**		and the dispatcher will trigger the corresponding function.
**		- no match, no response.
*/

int				loop_user_input(t_sct *s)
{
	static long	buffer = { 0 };
	int			ret;

	while (buffer != K_ENTER)
	{
		buffer = 0;
		if (read(0, &buffer, 4) < 0)
			return (-1);
		if (buffer == '$' || NULL != get_sct()->buffer)
			search_mode(&buffer);
		else if (OK != (ret = select_mode(&buffer, s)))
			return (ret);
	}
	return (OK);
}

int				main(int ac, char **av)
{
	static t_sct s = { 0 };

	if (NULL == set_sct(&s)
		|| OK != check(ac)
		|| OK != get_argv(ac, av, &s)
		|| OK != load_termcaps(&s.term)
		|| OK != set_canonical(&s.termios)
		|| OK != handle_all_signal())
		quit_binary(s.elements, &s.termios);
	tputs(get_term()->hide_cursor, 1, putchar_0);
	get_window_and_print(&s);
	if (1 == loop_user_input(&s))
		print_value();
	clear_screen();
	quit_binary(s.elements, &s.termios);
	return (EXIT_SUCCESS);
}
