#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(char *str, int c)
{
	while (*str++)
		if (*str == c)
			return (str);
	return (NULL);
}

int 	do_op(int a, int b, int op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (b - a);
	if (op == '%')
		return (b % a);
	if (op == '/')
		return (b / a);
	if (op == '*')
		return (a * b);
	return (0);
}

int     ft_strlen(char *str)
{
	int k = 0;
	while(*str++)
		k++;
	return (k);
}

int		main(int argc, char ** argv)
{
	char *ptr = argv[1];
	int stack[4096];
	int top = 0;
	int ans = 0;

	if (argc == 2)
	{
		if (ptr[0] == '+' || ptr[0] == '*' || ptr[0] == '-' || ptr[0] == '/' || ptr[0] == '%'
				|| !ft_strlen(ptr))
		{
			printf("Erorr\n");
			exit (1);
		}
		else
		{
			stack[top++] = atoi(ptr);
			while (ptr)
			{
				ptr = ft_strchr(ptr, ' ');
				if (ptr == NULL)
					break ;
				//pop twice 
				//push ans to stack
				if (ptr[1] == '+' || ptr[1] == '*' || ptr[1] == '-' || ptr[1] == '/' ||ptr[1] == '%')
				{
					ans = do_op(stack[top-1], stack[top -2], ptr[1]);
					top -= 2;
					stack[top++] = ans;	
				}
				//push to stack
				else
					stack[top++] = atoi(ptr);
			}
		}
	}
	if (top == 1)
		printf("%d", ans);
	else
		printf("Error");	
	printf("\n");
	return (0);
}
