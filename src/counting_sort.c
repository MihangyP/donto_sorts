#include <donto_sorts.h>

void  counting_sort(int *tab, int size, bool visualizer)
{
  if (NULL == tab && size == 0)
    return ;
  int max;
  int *tmp_tab;
  int t;
  int j;
  int i;
  max = find_max(tab, size);
  tmp_tab = malloc((max + 1) * sizeof(int));
  if (NULL == tmp_tab)
    return ;
  for (i = 0; i <= max; ++i)
	  tmp_tab[i] = 0;
  i = -1;
  while (++i < size)
    tmp_tab[tab[i]]++; 
  i = -1;
  j = 0;
  while (++i <= max)
  {
    t = 0;
    while (t < tmp_tab[i])
    {
      tab[j] = i;
      ++t;
      ++j;
    }
  }
}
