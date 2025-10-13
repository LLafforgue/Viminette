/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:20:00 by llafforg          #+#    #+#             */
/*   Updated: 2025/10/11 17:07:33 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	*parse_arg(char *arg, int *hints)
{
	int	i;

	i = 0;
	while (i < 16)
		hints[i++] = arg[i] - 48;
	return (hints);
}

int	clean_arg(char *arg, char *tab)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] != ' '
			|| !(arg[i - 1] > '0' && arg[i - 1] < '5'))
			return (1);
		else
		{
			tab[j++] = arg[i - 1];
			i = i + 2;
		}
	}
	tab[15] = arg[30];
	if (i == 31 && j == 15)
	{
		tab[16] = '\0';
		return (0);
	}
	else
		return (1);
}

int compteur(int duo[4][2], int *hints, int *l, int *r)
{
	int i;

	i = 0;
	*l = 0;
	*r = 0;
	while (i < 4)
	{
		duo[i][0] = hints[i + 8];
		//printf("%d ", duo[i][0]);
		duo[i][1] = hints[i + 12];
		//printf("%d ", duo[i][1]);
		i ++;
	}
	i = 0;
	while (i < 4)
	{
		*l += duo[i++][0];
		//printf("%d ", l);
	}
	i = 0;
	while (i < 4)
		*r += duo[i++][1];
	return *l + *r;
}

// void print_7_10(int duo[4][2], int *left)
// {
// 	int i;
// 	int	j;

// 	j = left % 2;
// 	i = 0;
// 	while (i < 4)
// 	{
// 		j = 0;
// 	}
// }

int	main(int argc, char *argv[2])
{
	char	arg[17];
	int		hints[16];
	int		d_hint[4][2];
	int		left;
	int		right;
	int		count;

	clean_arg(argv[1], arg);
	if (argc != 2 || clean_arg(argv[1], arg) == 1 || *argv[1] == '\0')
	{
		write(1, "Enter 16 spaced digits in \"\" !\n", 30);
		return (1);
	}
	else
	{
		parse_arg(arg, hints);
		count = compteur(d_hint, hints, &left, &right);

	}

	if (16 <= count && 18 >= count && left > 6 && right > 6)
		{
			write(1, "ok\n", 3);
			printf("left :%d et right :%d", left, right);
			// if(count == 16)
			// 	left = 0;
			// if(count == 17)
			// 	{
			// 		if (left == 7 || right == 7)
			// 			print_7_10(d_hint);
			// 		else
			// 			left = 0;
			// 	}
			// if(count == 18)
			// 	left = 0;
		}
	else
		write(1, "Error!\n", 7);

	return (0);
}
