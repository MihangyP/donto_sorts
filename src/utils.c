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
	printf("\033[1;32mDescription:\033[0m\n %s\n", desc);
	printf("\033[1;32mTime complexity:\033[0m\n %s\n", complexity);
	printf("\033[1;32mResult:\033[0m\n ==> ");
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

int	find_min(int *tab, int size)
{
	int min;
	int i;

	i = 0;
	min = tab[i];
	++i;
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		++i;
	}
	return (min);
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
	int min;

	i = -1;
	width = SCREEN_WIDTH / size;
	pos_x = 0;
	max = find_max(tab, size);
	min = find_min(tab, size);
	while (++i < size)
	{
		if (tab[i] == max)
		{
			height = SCREEN_HEIGHT;
			pos_y = 0;
		}
		else if (tab[i] == min)
		{
			height = 5;
			pos_y = SCREEN_HEIGHT - 5;
		}
		else
		{
			int a = max - min;
			int b = SCREEN_HEIGHT - 5;
			int c = max - tab[i];
			int d = (c * b) / a;
			height = SCREEN_HEIGHT - d;
			pos_y = SCREEN_HEIGHT - height;
			/*height = (SCREEN_HEIGHT * tab[i]) / max;*/
			/*pos_y = SCREEN_HEIGHT - (SCREEN_HEIGHT * tab[i]) / max;*/
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

char	*normalize(char *name)
{
	char	*result_name;
	bool	found;
	int		i;

	result_name = malloc((strlen(name) + 1) * sizeof(char));
	if (NULL == result_name)
		return (NULL);
	found = false;
	i = -1;
	while (name[++i])
	{
		if (name[i] == '_')
		{
			result_name[i] = ' ';
			found = true;
		}
		else if (found)
		{
			result_name[i] = name[i] - 32;
			found = false;
		}
		else
			result_name[i] = name[i];
	}
	result_name[i] = '\0';
	return (result_name);
}

void	show_visualizer(t_tab *tab, char *name)
{
	bool	is_ready_to_sort;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, normalize(name));
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
		exec_and_show(selection_sort, tab->data, tab->size, SELECTION_SORT_DESCRIPTION, "O(n^2)");
	else if (strcmp(name, "Counting_sort") == 0)
		exec_and_show(counting_sort, tab->data, tab->size, COUNTING_SORT_DESCRIPTION, "O(n + k)");
	else if (strcmp(name, "Quick_sort") == 0)
		exec_and_show(quick_sort, tab->data, tab->size, QUICK_SORT_DESCRIPTION, "O(n * log(n))");
	else
		printf("TODO\n");
}
