#include <stdio.h>
#include <stdlib.h>

int ft_sqrt(int nb);
int main(int argc, char *argv[])
{
	(void) argc;
	int a = atoi(argv[1]);
	// int b = atoi(argv[2]);
	printf("%d\n", ft_sqrt(a));
}
