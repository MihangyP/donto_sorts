#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av)
{
	int n;
	int	max = 10;
	srand(time(NULL));
	if (ac > 2)
	{
		printf("Excess arguments\n");
		return (1);
	}
	if (ac > 1)
		max = atoi(av[1]);
	for (int i = 0; i < max; ++i)
	{
		n = rand() % 200;
		printf("%d ", n);
	}
	return (0);
}
