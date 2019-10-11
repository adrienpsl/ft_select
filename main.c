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

static void test(t_sct *s)
{
	s->elements = testing_array();
	s->size_el = get_min_size(s->elements);
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

static int fill_elements(int ac, char **av, t_sct *select)
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

int catch_and_treat_user_input(t_sct *s)
{
	static char buffer[5] = { 0 };
	int ret;

	ft_bzero(&buffer, 5);
	while (OK != ft_strcmp(buffer, "\n"))
	{
		ft_bzero(&buffer, 5);
		if (read(0, buffer, 4) < 0)
			return (-1);
		if (OK != (ret = dispatch_user_key(buffer, s)))
			return (ret);
	}
	return (OK);
}

int main(int ac, char **av)
{
	static t_sct s = { 0 };

	if (OK != check(ac)
		|| OK != fill_elements(ac, av, &s)
		|| OK != load_termcaps(&s.term)
		|| OK != set_canonical(&s.termios))
	{
		quit_binary(s.elements, &s.termios, s.termios_set);
	}
	test(&s);
	get_sct(&s);
	catch_all_signal();
	start_display(&s);
	if (1 == catch_and_treat_user_input(&s))
	{
		clear_screen();
		ftarray__func(s.elements, print_value, NULL);
	}
	quit_binary(s.elements, &s.termios, s.termios_set);
	return (EXIT_SUCCESS);
}