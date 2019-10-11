#include <ft_select.h>

static int check(int ac, t_sct *s)
{
	ft_bzero(s, sizeof(t_sct));
	if (ac == 1)
		return (1);
	if (1 != isatty(STDIN_FILENO))
	{
		ft_printf("That's not a term !");
		return (-1);
	}
	return (OK);
}

static void copy_argv_in_elements(int ac, char **av, t_sct *select)
{
	t_el el;
	int i;

	i = 1;
	while (i < ac)
	{
		ft_bzero(&el, sizeof(t_el));
		el.text = av[i];
		ftarray__push(select->elements, &el);
		i += 1;
	}
}

static int init_ftselect(int ac, char **av, t_sct *select)
{
	if (NULL == (select->elements = ftarray__init(ac, sizeof(t_sct))))
		return (-1);
	copy_argv_in_elements(ac, av, select);
	select->size_el = get_min_size(select->elements);
	return (OK);
}

int main(int ac, char **av)
{
	g_test = 0;
	t_sct s;

	if (OK == check(ac, &s)
		&& OK == init_ftselect(ac, av, &s)
		&& OK == load_term_caps(&s.term)
		&& OK == set_canonical_mode(&s.termios))
	{
		clear_screen(&s.term);
		s.elements = testing_array();
		s.size_el = get_min_size(s.elements);
		g_select = &s;
		get_window_size(&s.window, s.elements->length, s.size_el);
		print_data(s.elements, &s.term, &s.window, s.size_el);
		catch_all_signal();
		ms__get_line(&s);
	}
	ftarray__free(&s.elements);
	return 0;
}