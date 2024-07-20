#include <donto_sorts.h>

int	main(int ac, char **av)
{
	t_tab	*tab;

	handle_args_errors(ac, av);
	tab = catch_data(ac, av);
	if (NULL == tab)
		return (69);
	if (strcmp(av[2], "--visualize") == 0 || strcmp(av[2], "-v") == 0)
	{
		show_visualizer(tab, av[1]);
		free(tab->data);
		free(tab);
		return (0);
	}
	run_sort(tab, av[1]);
	free(tab->data);
	free(tab);
	return (0);
}
