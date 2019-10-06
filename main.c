#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <libft.h>
#include <ft_select.h>

//static void winsz_handler(int sig)
//{
//	(void)sig;
//	const char *s = "winsize changed!\n";
//	write(STDOUT_FILENO, s, strlen(s));
//}

//static int check_and_init()
//{
//	char *name;
//	char *type;
//
//	printf("%d \n", isatty(STDIN_FILENO));
//	if (1 == isatty(STDIN_FILENO)
//		&& NULL != (name = ttyname(STDIN_FILENO))
//		&& NULL != (type = getenv("TERM"))
//		)
//	{
//		printf("%s  %s\n,", name, type);
//		return (OK);
//	}
//	return (-1);
//}

void get_z(int a);
void get_z(int a)
{
	(void)a;
	ft_printf("Please do to kill the app in this way,"
			  "I need to clean up some stuff");
	//	signal(SIGTSTP, SIG_DFL);
}

// catch with the read all the signal that I send
int main(void)
{
	struct termios new_termios;

	signal(SIGKILL, get_z);
	char buffer[10];
	int i;

	set_canonical_mode(&new_termios);
	while (1)
	{
		// je start ici, et je peux catch les sinaux la ?
		ft_bzero(&buffer, 10);
		read(0, buffer, 10);
		i = 0;
		while (i < 10)
		{
			printf("%d.", buffer[i]);
			if ('\x1a' == buffer[i])
				printf("-true -");
			i++;
		}
		if (32 == buffer[0])
			break;
		printf("\n");
		//		check_and_init();
		//		printf("slot %d \n", ttyslot());
		//		ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
	}
	unset_canonical_mode(&new_termios);
	while (1);

	//	signal(SIGWINCH, winsz_handler);
	//
	//	struct winsize w;
	//
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
	//	sleep(1);
	//	while (1)
	//	    ;

	return 0;
}