#include <donto_sorts.h>

void	insertion_sort(int *tab, int size)
{
	if (NULL == tab || size == 0)
		return ;
	int i;
	int	j;
	int	tmp;

	i = 0;
	while (++i < size)
	{
		j = i; 
		while (j > 0 && tab[j - 1] > tab[j])
		{
			tmp = tab[j - 1];
			tab[j - 1] = tab[j];
			tab[j] = tmp;
			--j;
		}
	}
}
