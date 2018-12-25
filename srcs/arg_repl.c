/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_repl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:08:41 by tduval            #+#    #+#             */
/*   Updated: 2018/12/25 22:27:05 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static void	wave_case(char **argv, t_env *envi, int i)
{
	char	*om;

	if (!(om = get_enval(envi, "HOME")))
		return ;
	if (!(argv[i] = ft_strjoin(om, argv[i] + 1)))
		return ;
	free(om);
}

static void	dolar_case(char **argv, t_env *envi, int i)
{
	char	*tmp;

	if (!(tmp = get_enval(envi, argv[i] + 1)))
	{
		free(argv[i]);
		if (!(argv[i] = ft_strdup("")))
			return ;
	}
	else
	{
		free(argv[i]);
		if (!(argv[i] = ft_strdup(tmp)))
		{
			free(tmp);
			return ;
		}
		free(tmp);
	}
}

char		**arg_repl(char **argv, t_env *envi)
{
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i][0] == '$')
			dolar_case(argv, envi, i);
		else if (argv[i][0] == '~')
			wave_case(argv, envi, i);
	}
	return (argv);
}
