#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <libft.h>
#include <ft_select.h>
#include <curses.h>
#include <termcap.h>

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

void write_underline(char *text)
{
	char *underline_cmd = tgetstr("us", NULL);
	tputs(underline_cmd, 1, ft_putchar);

}

int main(int ac, char **av)
{
	g_test = 0;
	if (OK != check(ac)
		|| OK != load_term_caps()
		|| OK != init_ftselect(ac, av, &g_select)
		|| OK != set_canonical_mode(&g_select.termios))
		return (EXIT_FAILURE);


	char *inverse_cmd = tgetstr("mr", NULL);
//	char* color_cap = tgetstr("AF", NULL);

	tputs(inverse_cmd, 1, putchar);

	printf("Cool ! Maintenant j'ecris en vert !\n");
//	catch_all_signal();
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