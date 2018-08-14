#include <unistd.h>

int		matches(int a, int b)
{
	return ((a == '{' && b == '}') ||
			(a == '(' && b == ')') ||
			(a == '[' && b == ']'));
}

int		brackets(char *str)
{
	int		stack[4096];
	int		top = 0;
	int 	i = 0;

	while(str[i])
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			stack[++top] = str[i];
		if (str[i] == '}' || str[i] == ']' || str[i] == ')')
			if (!matches(stack[top--], str[i]))
				return (0);
		i++;
	}
	return (!top);
}

int		main(int argc, char ** argv)
{
	int k = 1;
	if (argc > 1)
	{
		while (k < argc)
		{
			if(brackets(argv[k]))
				write(1, "OK\n",3);
			else
				write(1, "Error\n", 6);
			k++;
		}
	}
	if (argc == 1)
		write(1, "\n", 1);
	return (0);
}
