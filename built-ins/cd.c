/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 03:58:04 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 02:04:30 by tduval           ###   ########.fr       */
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
	char	path[256];

	pothome = 0;
	if (!argv[1])
	{
		if (!(pothome = get_enval(envi, "HOME")))
		{
			ft_putendl("cd: \"HOME\" variable not found.");
			return (1);
		}
		getcwd(path, 256);
		ch_enval(envi, "OLDPWD",  path);
		chdir(pothome);
		ch_enval(envi, "PWD", pothome);
		ft_strdel(&pothome);
	}
	else
	{
		if (ft_strequ(argv[1], "-"))
		{
			pothome = get_enval(envi, "OLDPWD");
			getcwd(path, 256);
			ch_enval(envi, "OLDPWD", path);
			chdir(pothome);
			ch_enval(envi, "PWD", pothome);
			ft_strdel(&pothome);
			return (1);
		}
		else if ((lstat(argv[1], &buf) == -1))
			ft_printf("cd: no such file or directoy: %s\n", argv[1]);
		else if (S_ISDIR(buf.st_mode))
		{
			getcwd(path, 256);
			if (chdir(argv[1]) == -1)
				ft_printf("cd: permission denied: %s\n", argv[1]);
			else
			{
				ch_enval(envi, "OLDPWD", path);
				ch_enval(envi, "PWD", argv[1]);
			}
		}
		else
			ft_printf("cd: not a directory: %s\n", argv[1]);
	}
	return (1);
}
