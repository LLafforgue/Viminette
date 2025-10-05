#include <unistd.h>

// int ft_error(int n)
// {
// 	if(n <= 0 | n > 9)
// 		return (1);
// }

void	ft_print_once(int i, char *buff)
{
	while ('0' <= buff[i] && '9'>= buff[i])
	{
		write(1, &buff[i--], 1);
	}
}

void	ft_init(int n, char *buff)
{
	if (n <= 0)
		return ;
	buff[n - 1] = buff[n] + 1 ;
	ft_init(n - 1, buff);
}

void	ft_inc_rec(int i, int n, char *buff)
{
	if (i == n)
		return ;
	if (buff[i] == '9' - i)
		ft_inc_rec(i + 1, n, buff);
	else
	{
		while (i >= 0)
		{
			buff[i--] += 1;
			if(i >= 0)
				buff[i] = buff[i + 1];
		}
	}
	
}

void	ft_print_combn(int n)
{
	char	buff[8];
	if(n <= 0 | n > 9)
		return ;
	buff[n - 1] = '0';
	ft_init(n - 1, buff);
	ft_print_once(n - 1, buff);
	while (buff[n - 1] != '9' - n + 1)
	{
		write(1, ", ", 2);
		ft_inc_rec(0, n, buff);
		ft_print_once(n - 1, buff);
	}
}

int main(void)
{
	ft_print_combn(4);
	return (0);
}