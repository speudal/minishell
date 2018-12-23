/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_repl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:08:41 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 23:53:51 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static void	wave_case(char **argv, t_env *envi, int i)
{
	int		j;
	char	*tmp2;
	char	*tmp;
	char	*om;

	j = 0;
	if (!(om = get_enval(envi, "HOME")))
		return ;
	while (argv[i][j])
		j++;
	if (!(tmp = ft_strnew(j)))
		return ;
	j = -1;
	while (argv[i][++j] != '~')
		tmp[j] = argv[i][j];
	if (!(tmp2 = ft_strjoin(tmp, om)))
		return ;
	free(tmp);
	if (!(tmp = ft_strjoin(tmp2, argv[i] + j + 1)))
		return ;
	free(tmp2);
	free(argv[i]);
	if (!(argv[i] = ft_strdup(tmp)))
		return ;
	free(tmp);
	free(om);
}

char		**arg_repl(char **argv, t_env *envi)
{
	int		i;
	char	*tmp;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '$')
		{
			if (!(tmp = get_enval(envi, argv[i] + 1)))
			{
				free(argv[i]);
				if (!(argv[i] = ft_strdup("")))
					return (0);
			}
			else
			{
				free(argv[i]);
				if (!(argv[i] = ft_strdup(tmp)))
					return (0);
				free(tmp);
			}
		}
		else if (ft_strchr(argv[i], '~'))
			wave_case(argv, envi, i);
		i++;
	}
	return (argv);
}
