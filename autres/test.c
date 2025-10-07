#include <stdio.h>

// int ft_fibonacci(int index)
// {
// 	int buff[2];

// 	buff[0] = 1;
// 	buff[1] = 1;
// 	if (index < 0)
// 		return -1;
// 	if (index == 0)
// 		return 0;
// 	while(index > 2)
// 	{
// 		buff[index % 2] += buff[(index + 1) % 2];
// 		index --;
// 	}
// 	return buff[(index + 1) % 2];
// }

int ft_fibonacci(int index)
{
	int x;

	x = 1;
	if (index < 0)
		return -1;
	if (index == 0)
		return 0;
	if (index > 2)
		return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	
	return x;
}

int main(void)
{
	int nbr;
	nbr = ft_fibonacci(5);
	printf("la fonction renvoie %d\n", nbr);
	nbr = ft_fibonacci(4);
	printf("la fonction renvoie %d\n", nbr);
	return (0);
}