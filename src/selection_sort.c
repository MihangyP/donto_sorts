#include <donto_sorts.h>

static size_t	is_min(int n, int *tab, int i, int size)
{
	while (i < size)
	{
		if (n > tab[i])
			return (0);
		++i;
	}
	return (1);
}

void	selection_sort(int *tab, int size, bool visualizer)
{
	if (NULL == tab || size == 0)
		return ;
	int	i;
	int	j;
	int	t;

	i = -1;
	while (++i < size)
	{
		j = i;
		t = j;
		while (j < size)
		{
			if (is_min(tab[j], tab, i, size))
				t = j;
			j++;
		}
		swap(&tab[i], &tab[t]);
		if (visualizer == WITH_VISUALIZER)
		{
			BeginDrawing();
			ClearBackground(BACKGROUND_COLOR);
			draw_items(tab, size, &tab[i], &tab[t]);
			sleep(TIME);
			EndDrawing();
		}
	}
}
