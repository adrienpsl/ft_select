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
	if (OK != check(ac)
		|| OK != init_ftselect(ac, av, &g_select)
		|| OK != load_term_caps()
		|| OK != set_canonical_mode(&g_select.termios))
		return (EXIT_FAILURE);
	clear_screen();
	g_select.elements = testing_array();
	g_select.size_el = get_min_size(g_select.elements);
	get_window_size(&g_select.window, g_select.elements->length);
	loop_and_print(g_select.elements);
//	printf("-- %d %d\n", g_select.window.elem_by_line,
//		g_select.window.nb_lines);
	//	loop_and_print(g_select.elements);
	//
	catch_all_signal();
	ms__get_line();
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