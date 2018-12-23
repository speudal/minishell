/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:09:32 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 03:11:17 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minishell.h>
#include "libft.h"

static int	count_args(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int			main(void)
{
	char	*com;
	char	**argv;
	int		argc;

	com = 0;
	argv = 0;
	while (69)
	{
		write(1, "\e[32m$> \e[39m", 14);
		com = 0;
		if (get_next_line(1, &com))
		{
			if (!(argv = ft_strsplit(com, ' ')))
				return (0);
			argc = count_args(argv);
			if (argv[0])
			{
				if (!(hub(argv)))
					ft_printf("minishell: %s: command not found.\n", argv[0]);
			}
			free_split(argv);
			ft_strdel(&com);
		}
	}
	return (0);
}
