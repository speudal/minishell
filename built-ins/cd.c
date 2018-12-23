/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 03:58:04 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 04:27:07 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static char	*get_home(void)
{
	extern char	**environ;
	char		*tmp;
	int			i;

	tmp = 0;
	i = 0;
	while (environ[i] && ft_strcmp(tmp, "HOME="))
	{
		i++;
		ft_strdel(&tmp);
		if (!(tmp = ft_strsub(environ[i], 0, 5)))
			return (0);
	}
	ft_strdel(&tmp);
	return (environ[i]? ft_strdup(environ[i] + 5) : 0);
}

int			bi_cd(char **argv)
{
	char	*pothome;

	pothome = 0;
	if (!argv[1])
	{
		if (!(pothome = get_home()))
			return (0);
		chdir(pothome);
		ft_strdel(&pothome);
	}
	else
		chdir(argv[1]);
	return (1);
}
