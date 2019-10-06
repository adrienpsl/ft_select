#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <string.h>
#include <ft_select.structures.h>

static void winsz_handler(int sig)
{
	(void)sig;
	const char *s = "winsize changed!\n";
	write(STDOUT_FILENO, s, strlen(s));
}

int main(void)
{
	signal(SIGWINCH, winsz_handler);

	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	printf("lines %d\n", w.ws_row);
	printf("columns %d\n", w.ws_col);

	printf("\033[8;40;100t");
	fflush(stdout);
	tcdrain(STDOUT_FILENO);

	// remove this comment, then it works on my machine
	// However, it's ad hoc because there is no garantee
	//usleep(100000);

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	printf("lines %d\n", w.ws_row);
	printf("columns %d\n", w.ws_col);
	sleep(1);
	while (1)
	    ;

	return 0;
}