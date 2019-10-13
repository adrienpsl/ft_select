#include <ft_select.h>

// TODO : rebuild here a func with no space for the last one
static int print_value(void *p_el, void *null)
{
	t_el *el;

	(void)null;
	el = p_el;
	if (el->is_selected)
		ft_printf("%s ", el->text);
	return (0);
}

static int check(int ac)
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

static int get_argv(int ac, char **av, t_sct *select)
{
	t_el el;
	int i;

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
	return (OK);
}

// je fais une current line,
// if user tap /, 
// I add the char to the current line, 
// and select all the matched,
// I need to validate with enter

// add to buffer :
int loop_user_input(t_sct *s)
{
	static long buffer = { 0 };
	int ret;

	while (buffer != K_ENTER)
	{
		buffer = 0;
		if (read(0, &buffer, 4) < 0)
			return (-1);
		if (buffer == '$' || NULL != *get_buffer())
		{
			if (buffer == '$' && *get_buffer())
				ft_dprintf(1, *get_buffer());
			if (*get_buffer() == NULL)
			{
				if (NULL == (*get_buffer() = ft_strdup((char *)buffer)))
					return (0);
			}
			else
				ft_pstrjoin(*get_buffer(), (char*)buffer, 1, get_buffer());
		}
		else if (OK != (ret = dispatch_user_key(&buffer, s)))
			return (ret);
	}
	return (OK);
}

int main(int ac, char **av)
{
	static t_sct s = { 0 };

	if (OK != check(ac)
		|| OK != get_argv(ac, av, &s)
		|| OK != load_termcaps(&s.term)
		|| OK != set_canonical(&s.termios)
		|| OK != handle_all_signal()
		|| OK != set_sct(&s))
		quit_binary(s.elements, &s.termios);
	test(&s);
	get_window_and_print(&s);
	if (1 == loop_user_input(&s))
	{
		clear_screen();
		ftarray__func(s.elements, print_value, NULL);
	}
	clear_screen();
	quit_binary(s.elements, &s.termios);
	return (EXIT_SUCCESS);
}