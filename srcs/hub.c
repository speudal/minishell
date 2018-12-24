/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:31:58 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 03:47:48 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static int	path_prog(char **argv, t_env *envi)
{
	int		i;
	char	**vne;
	char	**path;

	i = 0;
	vne = copy_env(envi);
	if (!(path = get_path(vne)))
	{
		free_split(vne);
		return (0);
	}
	while (path[i] && !(act_prog(path[i], argv, vne)))
		i++;
	i = path[i] ? 1 : 0;
	free_split(path);
	free_split(vne);
	return (i);
}

static int	local_command(char **argv, t_env *envi)
{
	pid_t		new;
	int			status;
	char		**vne;
	t_stat		buf;

	lstat(argv[0], &buf);
	if (S_IXUSR & buf.st_mode)
	{
		vne = copy_env(envi);
		new = fork();
		if (new == 0)
			execve(argv[0], argv, vne);
		else if (new > 0)
			new = wait(&status);
		free_split(vne);
		return (1);
	}
	return (0);
}

static void	free_env(t_env *envi)
{
	t_env	*tmp;

	while (envi)
	{
		tmp = envi->next;
		ft_strdel(&envi->var);
		ft_strdel(&envi->val);
		free(envi);
		envi = tmp;
	}
}

int			hub(char **argv, t_env *envi)
{
	if (ft_strequ(argv[0], "env"))
		return (bi_env(argv, envi));
	else if (ft_strequ(argv[0], "echo"))
		return (bi_echo(argv));
	else if (ft_strequ(argv[0], "setenv"))
		return (bi_setenv(argv, envi));
	else if (ft_strequ(argv[0], "unsetenv"))
		return (bi_unsetenv(argv, envi));
	else if (ft_strequ(argv[0], "cd"))
		return (bi_cd(argv, envi));
	else if (ft_strequ(argv[0], "exit"))
	{
		free_split(argv);
		free_env(envi);
		exit(0);
	}
	else if (path_prog(argv, envi))
		return (1);
	else if (local_command(argv, envi))
		return (1);
	return (0);
}
