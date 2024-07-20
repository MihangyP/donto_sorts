#include <donto_sorts.h>

void	bubble_sort(int *tab, int size, bool visualizer)
{
	if (NULL == tab || 0 == size)
		return ;
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				swap(&tab[j], &tab[j + 1]);
				if (visualizer == WITH_VISUALIZER)
				{
					BeginDrawing();
					ClearBackground(BACKGROUND_COLOR);
					draw_items(tab, size, &tab[j], &tab[j + 1]);
					sleep(1);
					EndDrawing();
				}
			}
		}
	}
}
