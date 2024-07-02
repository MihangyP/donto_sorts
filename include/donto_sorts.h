#ifndef	DONTO_SORTS_H
#	define 	DONTO_SORTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum	e_bool
{
	false,
	true
};

/* errors management fuctions prototypes */
void	handle_args_errors(int ac, char **av);
/* sort algorithms prototypes */
void	bubble_sort(int *tab, int size);
void	insertion_sort(int *tab, int size);

#endif
