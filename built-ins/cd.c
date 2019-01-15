/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 03:58:04 by tduval            #+#    #+#             */
/*   Updated: 2018/12/25 22:59:10 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "minishell.h"
#include "libft.h"

static void	no_mod_case(t_env *envi)
{
	char	*pothome;
	char	path[256];

	if (!(pothome = get_enval(envi, "HOME")))
		ft_putendl("cd: \"HOME\" variable not found.");
	else
	{
		getcwd(path, 256);
		if (chdir(pothome) == -1)
			ft_printf("cd: permission denied: %s\n", pothome);
		else
		{
			ch_enval(envi, "OLDPWD", path);
			ch_enval(envi, "PWD", pothome);
		}
		ft_strdel(&pothome);
	}
}

static void	less_case(t_env *envi)
{
	char	*pothome;
	char	path[256];

	if (!(pothome = get_enval(envi, "OLDPWD")))
		return ;
	if (chdir(pothome) == -1)
		ft_printf("cd: permission denied: %s\n", pothome);
	else
	{
		getcwd(path, 256);
		ch_enval(envi, "OLDPWD", path);
		ch_enval(envi, "PWD", pothome);
	}
	ft_strdel(&pothome);
}

static void	regular_case(char **argv, t_env *envi)
{
	char	path[256];

	getcwd(path, 256);
	if (chdir(argv[1]) == -1)
		ft_printf("cd: permission denied: %s\n", argv[1]);
	else
	{
		ch_enval(envi, "OLDPWD", path);
		getcwd(path, 256);
		ch_enval(envi, "PWD", path);
	}
}

int			bi_cd(char **argv, t_env *envi)
{
	t_stat	buf;

	if (!argv[1])
		no_mod_case(envi);
	else
	{
		if (ft_strequ(argv[1], "-"))
			less_case(envi);
		else if ((lstat(argv[1], &buf) == -1))
			ft_printf("cd: no such file or directory: %s\n", argv[1]);
		else if (S_ISDIR(buf.st_mode))
			regular_case(argv, envi);
		else
			ft_printf("cd: not a directory: %s\n", argv[1]);
	}
	return (1);
}
