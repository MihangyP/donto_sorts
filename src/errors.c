#include <donto_sorts.h>

static size_t	is_not_digit(char c)
{
	return (!(c >= 48 && c <= 57));
}

static void	show_usage_message(int ac, size_t is_wrong)
{
	{
		if (ac == 1)
			printf("ERROR: Missing argument\n");
	}
	{
		if (is_wrong)
			printf("ERROR: Wrong argument name\n");
	}
	printf("Usage: ./donto_sort <sort_algorithm_name> <...integer>\n");
	printf("Available sort_algorithm_name:\n");
	printf("- Bubble_sort\n"
			"- Insertion_sort\n"
			"- Quicksort\n"
			"- Shell_sort\n"
			"- Merge_sort\n"
			"- Selection_sort\n");
} 

static size_t	is_wrong_argument(char **av, int ac)
{
	char	*sort_algorithms_names[6] = {"Bubble_sort",
											"Insertion_sort",
											"Quick_sort",
											"Shell_sort",
											"Merge_sort",
											"Selection_sort"};
	int		i;
	int		j;
	char	*sort_algo_name;

	i = -1;
	while (++i < 6)
	{
		sort_algo_name = sort_algorithms_names[i];
		if (strcmp(av[1], sort_algo_name) == 0)
			return (false);
	}
	i = 2;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (is_not_digit(av[i][j]))
				return (true);
			++j;
		}
		++i;
	}
	return (true);
}

void	handle_args_errors(int ac, char **av)
{
	size_t	is_wrong = 0;
	if (ac > 2)
		is_wrong = is_wrong_argument(av, ac);
	if (ac <= 2 || is_wrong)
	{
		show_usage_message(ac, is_wrong);
		exit(69);
	}
}
