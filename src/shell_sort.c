#include <stdio.h>
#include <stdlib.h>

void	shell_sort(int *tab, int size)
{
	if (NULL == tab || size == 0)
		return ;
	// TODO
}

int main()
{
	int tab[5] = {1, -9, 69, 10, 2};
	for (int i = 0; i < 5; ++i)
		printf("%d ", tab[i]);
	shell_sort(tab, 5);
	printf("\n");
	for (int i = 0; i < 5; ++i)
		printf("%d ", tab[i]);
}
