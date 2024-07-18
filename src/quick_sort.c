#include <stdio.h>
#include <stdlib.h>

/* quick sort in Python */
/*
def quicksort(array):
	if len(array) < 2:
		return array;
	else:
		pivot = array[0];
		less = [i for i in array[1:] if i <= pivot]
		greater = [i kkk];
	return quicksort(less) + pivot + quicksort(greater)
*/

int	count_less_size(int *tab, int size, int pivot)
{
	int i = 0;
	int counter = 0;
	while (i < size)
	{
		if (tab[i] <= pivot)
			++counter;
		++i;
	}
	return (counter);
}

int	count_greater_size(int *tab, int size, int pivot)
{
	int i = 0;
	int counter = 0;
	while (i < size)
	{
		if (tab[i] > pivot)
			++counter;
		++i;
	}
	return (counter);
}

void	print_tab(int *tab, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", tab[i]);
}

int	*quick_sort(int *tab, int size)
{
	int i;
	int j;
	int pivot;
	int size_less;
	int size_greater;
	int *less = NULL;
	int *greater = NULL;
	if (NULL == tab || size == 0)	
		return (NULL);
	if (size == 1)
		return (tab);
	else
	{
		pivot = tab[0];
		size_less = count_less_size(tab, size, pivot);
		if (size_less > 0)
		{
			less = malloc(size_less * sizeof(int));
			if (NULL == less)
				return (NULL);
			i = -1;
			j = 0;
			while (++i < size)
			{
				if (tab[i] <= pivot)
				{
					less[j] = tab[i];
					++j;
				}
			}
		}
		size_greater = count_greater_size(tab, size, pivot);
		if (size_greater > 0)
		{
			greater = malloc(size_greater * sizeof(int));
			if (NULL == greater)
				return (NULL);
			i = -1;
			j = 0;
			while (++i < size)
			{
				if (tab[i] > pivot)
				{
					greater[j] = tab[i];
					++j;
				}
			}
		}
	}
	/*print_tab(less, size_less);*/
	/*printf("\n===========\n");*/
	/*print_tab(greater, size_greater);*/
	/*return (NULL);*/
	return (assembling(quick_sort(less, size_less), pivot, quick_sort(greater, size_greater)));
}

int main(void)
{
	int tab[5] = {66, 1, -9, 10, 69};
	/*
	for (int i = 0; i < 5; ++i)
		printf("%d ", tab[i]);
	*/
	quick_sort(tab, 5);
}
