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
	printf("Usage: ./donto_sort <sort_algorithm_name> <...integers>\n");
	printf("Available sort_algorithm_name:\n");
	printf("- Bubble_sort\n"
			"- Insertion_sort\n"
			"- Quicksort\n"
			"- Selection_sort\n"
      		"- Counting_sort\n");
} 

#define CAPACITY 5
static size_t	is_wrong_argument(char **av, int ac)
{
	char	*sort_algorithms_names[CAPACITY] = {"Bubble_sort",
											"Insertion_sort",
											"Quick_sort",
											"Selection_sort",
											"Counting_sort"};
	int		i;
	int		j;
	char	*sort_algo_name;

	i = -1;
	while (++i < CAPACITY)
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
