#include <string.h>

int    ft_strcmp(char *s1, char *s2)
{
	size_t k = 0;
	while (s1[k] && (s1[k] == s2[k]))
		k++;
	return (s1[k]-s2[k]);
}
