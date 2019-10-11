#include <ft_select.h>

// catch with the read all the signal that I send
static int check(int ac)
{
	if (ac == 1)
		return (1);
	if (1 != isatty(STDIN_FILENO))
	{
		ft_printf("That's not a term !");
		return (-1);
	}
	return (OK);
}

int main(int ac, char **av)
{
	g_test = 0;
	t_sct s;

	if (OK != check(ac)
		|| OK != init_ftselect(ac, av, &s)
		|| OK != load_term_caps(&s.term)
		|| OK != set_canonical_mode(&s.termios))
		return (EXIT_FAILURE);
	clear_screen(&s.term);
	s.elements = testing_array();
	s.size_el = get_min_size(s.elements);
	g_select = &s;
	get_window_size(&s.window, s.elements->length, s.size_el);1
	loop_and_print(s.elements, &s.term, &s.window, s.size_el);
//	printf("-- %d %d\n", g_select.window.elem_by_line,
//		g_select.window.nb_lines);
	//	loop_and_print(g_select.elements);
	//
	catch_all_signal();
	ms__get_line(&s);
	//		ioctl(STDIN_FILENO, TIOCSIG, SIGTSTP);
	//	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	//	printf("lines %d\n", w.ws_row);
	//	printf("columns %d\n", w.ws_col);
	//
	//	printf("\033[8;40;100t");
	//	fflush(stdout);
	//	tcdrain(STDOUT_FILENO);

	// remove this comment, then it works on my machine
	// However, it's ad hoc because there is no garantee
	//usleep(100000);

	//	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	//	printf("lines %d\n", w.ws_row);
	//	printf("columns %d\n", w.ws_col);
	return 0;
}