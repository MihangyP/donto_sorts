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

void	selection_sort(int *tab, int size)
{
	if (NULL == tab || size == 0)
		return ;
	int	i;
	int	j;
	int	t;
	int	tmp;
	int	min;

	i = 0;
	while (i < size)
	{
		j = i;
		t = j;
		while (j < size)
		{
			if (is_min(tab[j], tab, i, size))
			{
				min = tab[j];
				t = j;
			}
			j++;
		}
		tmp = tab[i];
		tab[i] = min;
		tab[t] = tmp;
		++i;
	}
}
