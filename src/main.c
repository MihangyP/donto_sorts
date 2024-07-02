#include <donto_sorts.h>

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
		bubble_sort(tab, size);
	else
		printf("TODO\n");
	for (int i = 0; i < size; ++i)
		printf("%d ", tab[i]);
	printf("\n");
	return (0);
}
