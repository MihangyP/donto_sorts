#include <donto_sorts.h>

static void	show_usage_message(int ac, size_t is_wrong)
{
	{
		if (ac == 1)
			printf("ERROR: Missing argument\n");
		else if (ac > 2)
			printf("ERROR: Excess argument\n");
	}
	{
		if (is_wrong)
			printf("ERROR: Wrong argument name\n");
	}
	printf("Usage: ./donto_sort <sort_algorithm_name>\n");
	printf("Available sort_algorithm_name:\n");
	printf("- Bubble_sort\n"
			"- Insertion_sort\n"
			"- Quicksort\n"
			"- Shell_sort\n"
			"- Merge_sort\n"
			"- Selection_sort\n");
} 

static size_t	is_wrong_argument(char *str)
{
	char	*sort_algorithms_names[6] = {"Bubble_sort",
											"Insertion_sort",
											"Quick_sort",
											"Shell_sort",
											"Merge_sort",
											"Selection_sort"};
	int		i;
	char	*sort_algo_name;

	i = -1;
	while (++i < 6)
	{
		sort_algo_name = sort_algorithms_names[i];
		if (strcmp(str, sort_algo_name) == 0)
			return (false);
	}
	return (true);
}

void	handle_args_errors(int ac, char **av)
{
	size_t	is_wrong = 0;
	if (ac == 2)
		is_wrong = is_wrong_argument(av[1]);
	if (ac != 2 || is_wrong)
		show_usage_message(ac, is_wrong);
}
