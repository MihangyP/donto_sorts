#ifndef	DONTO_SORTS_H
#	define 	DONTO_SORTS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* sort algorithms descriptions */
# define BUBBLE_SORT_DESCRIPTION "It repeatly steps through a list, compares adjacent elements, and swaps them if they are in the wrong order.\n This process is repeated until the list is sorted"
# define INSERTION_SORT_DESCRIPTION  "It builds the final sorted list one item at a time, by repeatedly picking the next elementi\n and inserting it into its correct position among the previously sorted elements"

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
