#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <libft.h>
#include <ft_select.h>
#include <curses.h>
#include <termcap.h>
#include <stdbool.h>

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

static int ms__get_line(
	//	t_s *const line,
	//	char **output
)
{
	static char buffer[5] = { 0 };

	//	fts__clear(line);
	ft_bzero(&buffer, 5);
	while (OK != ft_strcmp(buffer, "\n"))
	{
		ft_bzero(&buffer, 5);
		if (read(0, buffer, 4) < 0)
			return (-1);
		ft_printf("%s", buffer);
		//		if (OK != ft_strcmp(buffer, "\n"))
		//			handle_input(env, buffer, line);
	}
	ft_printf("\n");
	//	*output = line->data;
	return (OK);
}

// regarder si j'ai assez de place :
// I need to handle the .5, but I will see that tomorow ? no now !!
bool is_screen_wide_enouth(int size_max, int nb_element)
{
	float nb_by_col;
	(void)nb_element;
	
	size_max += 1;
	if (-1 == ioctl(STDIN_FILENO, TIOCGWINSZ, &g_select.size))
		return (false);
	nb_by_col = ((float)g_select.size.ws_col / (float)size_max);
	printf("%.1f \n", nb_by_col);
	printf("%d \n", (int)(nb_by_col));
	return (size_max < g_select.size.ws_col);
}

int main(int ac, char **av)
{
	g_test = 0;
//	int a;
	if (OK != check(ac)
		|| OK != load_term_caps()
		|| OK != init_ftselect(ac, av, &g_select)
		|| OK != set_canonical_mode(&g_select.termios))
		return (EXIT_FAILURE);
	// test reverse
//	tputs(tgetstr("cl", NULL), 1, ft_putchar);
//	print_in_reverse("test in reverse    \n");
//	ft_printf("toto\n");
//	print_in_underline("test in reverse    \n");
//	ft_printf("toto\n");
//	print_in_underline_reverse("test in reverse    \n");
//	read(0, &a, 1);

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