#include <donto_sorts.h>

int find_max(int *tab, int size)
{
  int i = 0;
  int max = tab[i];
  while (i < size)
  {
    if (tab[i] > max)
      max = tab[i];
    ++i;
  }
  return (max);
}

void  counting_sort(int *tab, int size)
{
  if (NULL == tab && size == 0)
    return ;
  int max;
  int *tmp_tab;
  int t;
  int j;
  int i;
  max = find_max(tab, size);
  tmp_tab = malloc(max * sizeof(int));
  if (NULL == tmp_tab)
    return ;
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
