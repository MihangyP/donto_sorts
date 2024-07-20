#include <donto_sorts.h>

int partition(int *tab, int low, int high, int size, bool visualizer)
{
    int pivot;
    int i;
	int j;

	pivot = tab[high];
	i = low - 1;
	j = low - 1;
	while (++j <= high)
	{
        if (tab[j] < pivot) {
            i++;
            swap(&tab[i], &tab[j]);
			if (visualizer == WITH_VISUALIZER)
			{
				BeginDrawing();
				ClearBackground(BACKGROUND_COLOR);
				draw_items(tab, size, &tab[i], &tab[j]);
				sleep(1);
				EndDrawing();
			}
        }
	}
    swap(&tab[i + 1], &tab[high]);
	if (visualizer == WITH_VISUALIZER)
	{
		BeginDrawing();
		ClearBackground(BACKGROUND_COLOR);
		draw_items(tab, size, &tab[i + 1], &tab[high]);
		sleep(1);
		EndDrawing();
	}
    return (i + 1);
}

void run_quick_sort(int *tab, int low, int high, int size, bool visualizer)
{
	int pivot_index;

    if (low < high) {
        pivot_index = partition(tab, low, high, size, visualizer);
        run_quick_sort(tab, low, pivot_index - 1, size, visualizer);
        run_quick_sort(tab, pivot_index + 1, high, size, visualizer);
    }
}

void quick_sort(int *tab, int size, bool visualizer)
{
	if (size == 0 || NULL == tab)
		return ;
	run_quick_sort(tab, 0, size - 1, size, visualizer);
}
