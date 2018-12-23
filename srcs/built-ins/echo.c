/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 01:07:54 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 02:21:15 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char		*print_var(char *var)
{
	extern char	**environ;
	char		*true;
	char		*tmp;
	int			j;
	int			i;

	i = 0;
	tmp = 0;
	while (var[i] != ' ' && var[i])
		i++;
	if (!(true = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (var[i] != ' ' && var[i])
	{
		true[i] = var[i];
		i++;
	}
	true[i] = 0;
	i = 0;
	while (ft_strcmp(tmp, true) && environ[i])
	{
		ft_strdel(&tmp);
		if (!(tmp = ft_strsub(environ[i], 0, ft_strlen(true))))
			return (0);
		if (ft_strcmp(tmp, true))
			i++;
	}
	j = ft_strlen(true);
	ft_strdel(&true);
	ft_strdel(&tmp);
	return (environ[i] ? environ[i] + j + 1 : "");
}

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
			k = 0;
			while (argv[j][k])
			{
				if (argv[j][k] == '$' && argv[j][k + 1] && argv[j][k + 1] != ' ')
				{
					ft_putstr(print_var(argv[j] + k + 1));
					while (argv[j][k] && argv[j][k] != ' ')
						k++;
				}
				if (argv[j][k])
					ft_putchar(argv[j][k]);
				k++;
			}
			if (argv[j + 1])
				ft_putchar(' ');
			j++;
		}
	}
	if (i)
		ft_putchar('\n');
	return (1);
}
