#include <donto_sorts.h>

void	print_result(int *tab, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", tab[i]);
	printf("\n");

}

void	exec_and_show(void (*f)(int *, int, bool), int *tab, int size, char *desc, char *complexity)
{
	f(tab, size, 0);
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
				DrawRectangle(pos_x, pos_y, width, height, YELLOW);
			else
				DrawRectangle(pos_x, pos_y, width, height, BLUE);
		}
		else
			DrawRectangle(pos_x, pos_y, width, height, BLUE);
		pos_x += width;
	}
}
