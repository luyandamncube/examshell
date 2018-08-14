#include <unistd.h>

void 	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	putnbr(int n)
{
	char c;

	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n < 10)
	{
		c = n + '0';
		ft_putchar(c);
	}
	else
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
}

int 	main(int argc, char **argv)
{
	int k = 0;

	if (argc == 1)
		ft_putchar('0');
	else
	{
		while (argv[k])
			k++;
		putnbr(k - 1);
	}
	ft_putchar('\n');
	return (0);
}
