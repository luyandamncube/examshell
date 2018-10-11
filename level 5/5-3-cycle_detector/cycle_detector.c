#include <stdlib.h>
#include <string.h>
#include "list.h"

int        cycle_detector(const t_list *list)
{
	t_list *pt1;
	t_list *pt2;

	if (list == NULL)
		return (1);
	pt1 = (t_list *)list;
	pt2 = (t_list*)list;
	while (1)
	{
		pt1 = pt1->next;
		if (pt2->next == NULL)
			return (0);
		pt2 = pt2->next->next;
		if (pt1 == NULL || pt2 == NULL)
			return (0);
		if (pt1 == pt2)
			return (1);
	}
}
