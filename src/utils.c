#include <donto_sorts.h>

void	print_result(int *tab, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", tab[i]);
	printf("\n");

}

void	exec_and_show(void (*f)(int *, int), int *tab, int size, char *desc, char *complexity)
{
	f(tab, size);
	printf("Description:\n %s\n", desc);
	printf("Time complexity: %s\n", complexity);
	printf("Result:\n ==> ");
	print_result(tab, size);
}
