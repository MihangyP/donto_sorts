#include <donto_sorts.h>

int	main(int ac, char **av)
{
	int	*tab;
	int	size;
	int	i;
	int	j;
	int	is_ready_to_sort;

	handle_args_errors(ac, av);
	j = 2;
	if (strcmp(av[2], "--visualize") == 0 || strcmp(av[2], "-v") == 0)
		j = 3;
	size = ac - j;
	tab = malloc(size * sizeof(int));
	if (NULL == tab)
		return (1);
	i = 0;
	while (j < ac)
	{
		tab[i] = atoi(av[j]);
		++j;
		++i;
	}
	if (strcmp(av[2], "--visualize") == 0 || strcmp(av[2], "-v") == 0)
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, av[1]);
		SetTargetFPS(60);
		print_result(tab, size);
		while (!WindowShouldClose())
		{
			is_ready_to_sort = 0;
			BeginDrawing();
			ClearBackground(RAYWHITE);
			if (IsKeyPressed(KEY_A))
				is_ready_to_sort = 1;
			if (is_ready_to_sort)
			{
				if (strcmp(av[1], "Bubble_sort") == 0)
					bubble_sort(tab, size, 1);
				else if (strcmp(av[1], "Insertion_sort") == 0)
					insertion_sort(tab, size, 1);
				else if (strcmp(av[1], "Selection_sort") == 0)
					selection_sort(tab, size, 1);
				else if (strcmp(av[1], "Counting_sort") == 0)
					counting_sort(tab, size, 1);
				else if (strcmp(av[1], "Quick_sort") == 0)
					quick_sort(tab, size, 1);
				else
					printf("TODO\n");
			}
			draw_items(tab, size, NULL, NULL);
			EndDrawing();
		}
		CloseWindow();
		free(tab);
		return (0);
	}
	if (strcmp(av[1], "Bubble_sort") == 0)
		exec_and_show(bubble_sort, tab, size, BUBBLE_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(av[1], "Insertion_sort") == 0)
		exec_and_show(insertion_sort, tab, size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(av[1], "Selection_sort") == 0)
		exec_and_show(selection_sort, tab, size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(av[1], "Counting_sort") == 0)
		exec_and_show(counting_sort, tab, size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(av[1], "Quick_sort") == 0)
		exec_and_show(quick_sort, tab, size, INSERTION_SORT_DESCRIPTION, "O(n * log(n))");
	else
		printf("TODO\n");
	free(tab);
	return (0);
}
