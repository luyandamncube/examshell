int		max(int* tab, unsigned int len)
{
	unsigned int k = 0;
	int max = -2147483648;

	if (len == 0)
		return (0);	
	while (k < len)
	{
		if (tab[k] >= max)
			max = tab[k];
		k++;
	}
	return (max);
}
