/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 03:58:04 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 23:03:43 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "minishell.h"
#include "libft.h"

int			bi_cd(char **argv, t_env *envi)
{
	t_stat	buf;
	char	*pothome;

	pothome = 0;
	if (!argv[1])
	{
		if (!(pothome = get_enval(envi, "HOME")))
		{
			ft_putendl("cd: \"HOME\" variable not found.");
			return (1);
		}
		chdir(pothome);
		ft_strdel(&pothome);
	}
	else
	{
		if ((lstat(argv[1], &buf) == -1))
			ft_printf("cd: no such file or directoy: %s\n", argv[1]);
		else if (S_ISDIR(buf.st_mode))
			chdir(argv[1]);
		else
			ft_printf("cd: not a directory: %s\n", argv[1]);
	}
	return (1);
}
