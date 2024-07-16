#include <donto_sorts.h>

void	print_result(int *tab, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", tab[i]);
	printf("\n");

}

void	exec_and_show(void (*f)(int *, int), int *tab, int size, char *desc, char *complexity)
{
	f(tab, size);
	printf("Description:\n %s\n", desc);
	printf("Time complexity: %s\n", complexity);
	printf("Result:\n ==> ");
	print_result(tab, size);
}

int	main(int ac, char **av)
{
	int	*tab;
	int	size;
	int	i;
	int	j;

	handle_args_errors(ac, av);
	size = ac - 2;
	tab = malloc(size * sizeof(int));
	if (NULL == tab)
		return (1);
	i = 0;
	j = 2;
	while (j < ac)
	{
		tab[i] = atoi(av[j]);
		++j;
		++i;
	}
	if (strcmp(av[1], "Bubble_sort") == 0)
		exec_and_show(bubble_sort, tab, size, BUBBLE_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(av[1], "Insertion_sort") == 0)
		exec_and_show(insertion_sort, tab, size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(av[1], "Selection_sort") == 0)
		exec_and_show(selection_sort, tab, size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(av[1], "Counting_sort") == 0)
		exec_and_show(counting_sort, tab, size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else
		printf("TODO\n");
	free(tab);
	return (0);
}
