// test with 0 element
// test with 1 element
// test with 10 element

#include <libft.h>
#include <ft_select.h>

struct t
{
	int line_nb;

	int ac;
	char *av;

	int expected_int;
	char *expected_print;
	int expected_min_size;
};

static void print_array(t_array *array)
{
	t_el *el;

	array->i = 0;
	while (NULL != (el = ftarray__next(array)))
	{
		ft_printf("%s ", el->data);
	}
}

static void f_init_ftselect(struct t t)
{
	test_clear_testbuff();
	g_test = 1;
	char **argv = ft_strsplit(t.av, " ");
	t_sct select;

	int ret = init_ftselect(t.ac, argv, &select);
	if (ret == OK)
		print_array(select.elememens);
	if (test_cmp_int(t.expected_int, ret)
		|| test_cmp_buff(t.expected_print)
		|| test_cmp_int(t.expected_min_size, select.min_size))
		log_test_line(1, t.line_nb);

	if (argv)
		ft_strsplit_free(&argv);
	if (select.elememens)
		ftarray__free(&select.elememens);
	g_test = 0;
}

void test_init_ftselect(void);
void test_init_ftselect(void)
{
	// test with no element
	f_init_ftselect((struct t){ .line_nb = L,
		.ac = 1, .av = "name",
		.expected_int = -1,
		.expected_print = "",
		.expected_min_size = 0
	});

	f_init_ftselect((struct t){ .line_nb = L,
		.ac = 2, .av = "name toto",
		.expected_int = OK,
		.expected_print = "toto ",
		.expected_min_size = 4
	});

	f_init_ftselect((struct t){ .line_nb = L,
		.ac = 5, .av = "name toto titi supertoto hey",
		.expected_int = OK,
		.expected_print = "toto titi supertoto hey ",
		.expected_min_size = 9
	});
}