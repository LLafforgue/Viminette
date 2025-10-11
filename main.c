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
	{
		hints[i] = arg[i] - 48;
		i++;
	}
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
	if (i == 31 && j == 15)
	{
		tab[16] = '\0';
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char *argv[2])
{
	char	arg[17];
	int		hints[16];

	clean_arg(argv[1], arg);
	if (argc != 2 || clean_arg(argv[1], arg) == 1 || *argv[1] == '\0')
	{
		write(1, "Enter 16 spaced digits in \"\" !\n", 30);
		return (1);
	}
	else
		parse_arg(arg, hints);
	return (0);
}
