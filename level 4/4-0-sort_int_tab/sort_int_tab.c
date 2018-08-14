#include <string.h>

void sort_int_tab(int *tab, unsigned int size)
{
	size_t 	k = 0;
	size_t 	m = 0;
	int 	temp = 0;
	
	while (k < size)
	{
		m = k;
		while (m > 0)
		{
			if (tab[m] < tab[m -1])
			{
				temp = tab[m -1];
				tab[m -1] = tab[m];
				tab[m] = temp;
			}
			m--;
		}
		k++;
	}
}
