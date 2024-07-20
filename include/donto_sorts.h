#ifndef	DONTO_SORTS_H
#	define 	DONTO_SORTS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <raylib.h>
# include <stdbool.h>
# include <unistd.h>

/* screen size */
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 450

/* With visualizer or no */
# define WITH_VISUALIZER 1
# define NO_VISUALIZER 0

/* Colors */
# define BACKGROUND_COLOR SKYBLUE
# define ITEM_COLOR DARKGREEN
# define SWAP_ITEM_COLOR YELLOW

/* speed sorting in second */
# define TIME 0.9

/* sort algorithms descriptions */
# define BUBBLE_SORT_DESCRIPTION "It repeatly steps through a list, compares adjacent elements, and swaps them if they are in the wrong order.\n This process is repeated until the list is sorted"
# define INSERTION_SORT_DESCRIPTION  "It builds the final sorted list one item at a time, by repeatedly picking the next elementi\n and inserting it into its correct position among the previously sorted elements"
# define SELECTION_SORT_DESCRIPTION ""

/* Array of ints */
typedef struct s_tab
{
	int	*data;
	int	size;
}	t_tab;

/* errors management fuctions prototypes */
void	handle_args_errors(int ac, char **av);
/* sort algorithms prototypes */
void	bubble_sort(int *tab, int size, bool visualizer);
void	insertion_sort(int *tab, int size, bool visualizer);
void	selection_sort(int *tab, int size, bool visualizer);
void  counting_sort(int *tab, int size, bool visualizer);
void  quick_sort(int *tab, int size, bool visualizer);
/* utils */
void	print_result(int *tab, int size);
void	exec_and_show(void (*f)(int *, int, bool), int *tab, int size, char *desc, char *complexity);
void	swap(int *a, int *b);
void	draw_items(int *tab, int size, int *a, int *b);
int		find_max(int *tab, int size);
t_tab	*catch_data(int ac, char **av);
bool	is_sorted(int *tab, int size);
void	show_visualizer(t_tab *tab, char *name);
void	run_sort(t_tab *tab, char *name);

#endif
