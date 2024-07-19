#include <donto_sorts.h>

void	insertion_sort(int *tab, int size, bool visualizer)
{
	if (NULL == tab || size == 0)
		return ;
	int i;
	int	j;

	i = 0;
	while (++i < size)
	{
		j = i; 
		while (j > 0 && tab[j - 1] > tab[j])
		{
			swap(&tab[j - 1], &tab[j]);
			if (visualizer)
			{
				BeginDrawing();
				ClearBackground(RAYWHITE);
				draw_items(tab, size, &tab[j - 1], &tab[j]);
				sleep(1);
				EndDrawing();
			}
			--j;
		}
	}
}
