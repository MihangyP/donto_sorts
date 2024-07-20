#include <donto_sorts.h>

void	print_result(int *tab, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", tab[i]);
	printf("\n");

}

void	exec_and_show(void (*f)(int *, int, bool), int *tab, int size, char *desc, char *complexity)
{
	f(tab, size, NO_VISUALIZER);
	printf("Description:\n %s\n", desc);
	printf("Time complexity: %s\n", complexity);
	printf("Result:\n ==> ");
	print_result(tab, size);
}

int find_max(int *tab, int size)
{
  int i = 0;
  int max = tab[i];
  while (i < size)
  {
    if (tab[i] > max)
      max = tab[i];
    ++i;
  }
  return (max);
}

void	swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	draw_items(int *tab, int size, int *a, int *b)
{
	int i;
	int	width;
	int height;
	int pos_x;
	int	pos_y;
	int max;

	i = -1;
	width = SCREEN_WIDTH / size;
	pos_x = 0;
	max = find_max(tab, size);
	while (++i < size)
	{
		if (tab[i] == max)
		{
			height = SCREEN_HEIGHT;
			pos_y = 0;
		}
		else
		{
			height = (SCREEN_HEIGHT * tab[i]) / max;
			pos_y = SCREEN_HEIGHT - (SCREEN_HEIGHT * tab[i]) / max;
		}
		if (a != NULL && b != NULL)
		{
			if (&tab[i] == a || &tab[i] == b)
				DrawRectangle(pos_x, pos_y, width, height, SWAP_ITEM_COLOR);
			else
				DrawRectangle(pos_x, pos_y, width, height, ITEM_COLOR);
		}
		else
			DrawRectangle(pos_x, pos_y, width, height, ITEM_COLOR);
		pos_x += width;
	}
}

t_tab	*catch_data(int ac, char **av)
{
	int	d;
	int	o;
	t_tab *tab;

	d = 2;
	tab = malloc(sizeof(t_tab));
	if (NULL == tab)
		return (NULL);
	if (strcmp(av[2], "--visualize") == 0 || strcmp(av[2], "-v") == 0)
		d = 3;
	tab->size = ac - d;
	tab->data = malloc(tab->size * sizeof(int));
	if (NULL == tab->data)
		return (NULL);
	o = 0;
	while (d < ac)
	{
		tab->data[o] = atoi(av[d]);
		++d;
		++o;
	}
	return (tab);
}

bool	is_sorted(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				return (false);
			++j;
		}
	}
	return (true);
}

void	show_visualizer(t_tab *tab, char *name)
{
	bool	is_ready_to_sort;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, name);
	SetTargetFPS(60);
	print_result(tab->data, tab->size);
	while (!WindowShouldClose())
	{
		is_ready_to_sort = false;
		BeginDrawing();
		ClearBackground(BACKGROUND_COLOR);
		draw_items(tab->data, tab->size, NULL, NULL);
		if (!is_sorted(tab->data, tab->size) && !is_ready_to_sort)
			DrawText("Press D to start sorting", 190, 200, 20, BLACK);
		if (IsKeyPressed(KEY_D))
			is_ready_to_sort = true;
		if (is_ready_to_sort)
		{
			if (strcmp(name, "Bubble_sort") == 0)
				bubble_sort(tab->data, tab->size, WITH_VISUALIZER);
			else if (strcmp(name, "Insertion_sort") == 0)
				insertion_sort(tab->data, tab->size, WITH_VISUALIZER);
			else if (strcmp(name, "Selection_sort") == 0)
				selection_sort(tab->data, tab->size, WITH_VISUALIZER);
			else if (strcmp(name, "Counting_sort") == 0)
				counting_sort(tab->data, tab->size, WITH_VISUALIZER);
			else if (strcmp(name, "Quick_sort") == 0)
				quick_sort(tab->data, tab->size, WITH_VISUALIZER);
			else
				printf("TODO\n");
		}
		EndDrawing();
	}
	CloseWindow();
}

void	run_sort(t_tab *tab, char *name)
{
	if (strcmp(name, "Bubble_sort") == 0)
		exec_and_show(bubble_sort, tab->data, tab->size, BUBBLE_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(name, "Insertion_sort") == 0)
		exec_and_show(insertion_sort, tab->data, tab->size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(name, "Selection_sort") == 0)
		exec_and_show(selection_sort, tab->data, tab->size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(name, "Counting_sort") == 0)
		exec_and_show(counting_sort, tab->data, tab->size, INSERTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(name, "Quick_sort") == 0)
		exec_and_show(quick_sort, tab->data, tab->size, INSERTION_SORT_DESCRIPTION, "O(n * log(n))");
	else
		printf("TODO\n");
}
