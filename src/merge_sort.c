#include <donto_sorts.h>

void	merge_sort(int *tab, int size, bool visualizer)
{
	if (NULL == tab || size == 0)
		return ;
	if (size > 1)
	{
		int middle = size / 2;
		int rest = size - middle;
		int	*left = malloc(middle * sizeof(int));
		if (NULL == left)
			return ;
		int	*right = malloc(rest * sizeof(int));
		if (NULL == right)
			return ;
		int i = -1;
		while (++i < middle)
			left[i] = tab[i];
		int j = -1;
		while (i < size)
		{
			right[++j] = tab[i];
			++i;
		}
		merge_sort(left, middle, visualizer);
		merge_sort(right, rest, visualizer);
		int	tab_i = 0;
		int left_i = 0;
		int right_i = 0;
		while (left_i < middle && right_i < rest)
		{
			if (left[left_i] < right[right_i])
			{
				tab[tab_i] = left[left_i];
				left_i++;
			}
			else
			{
				tab[tab_i] = right[right_i];
				right_i++;
			}
			++tab_i;
		}
		while (left_i < middle)
		{
			tab[tab_i] = left[left_i];
			left_i++;
			tab_i++;
		}
		while (right_i < rest)
		{
			tab[tab_i] = right[right_i];
			right_i++;
			tab_i++;
		}
		free(right);
		free(left);
	}
}
