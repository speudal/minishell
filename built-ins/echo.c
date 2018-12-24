/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 01:07:54 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 03:02:02 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int			bi_echo(char **argv)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 1;
	if (argv[j])
	{
		if (ft_strcmp(argv[j], "-n") == 0)
		{
			i = 0;
			j++;
		}
		while (argv[j])
		{
			k = -1;
			while (argv[j][++k])
				ft_putchar(argv[j][k]);
			if (argv[j + 1])
				ft_putchar(' ');
			j++;
		}
	}
	if (i)
		ft_putchar('\n');
	return (1);
}
