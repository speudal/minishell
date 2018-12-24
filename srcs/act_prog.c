/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 22:12:24 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 03:00:36 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include "libft.h"
#include "minishell.h"

static void	do_it(char *path, char **argv, char **vne)
{
	int			status;
	pid_t		new_pid;

	new_pid = fork();
	if (new_pid == 0)
		execve(path, argv, vne);
	else if (new_pid > 0)
		new_pid = wait(&status);
	else if (new_pid == -1)
		ft_printf("Couldn't fork on %s.\n", path);
}

int			act_prog(char *path, char **argv, char **vne)
{
	DIR			*op;
	char		*tmp;
	char		*tmp2;
	t_dirent	*fil;
	t_stat		buf;

	if (!(op = opendir(path)))
		return (ft_printf("PATH: can't access to %s.\n", path));
	while ((fil = readdir(op)))
	{
		tmp = ft_strjoin(path, "/");
		tmp2 = ft_strjoin(tmp, fil->d_name);
		ft_strdel(&tmp);
		lstat(tmp2, &buf);
		if (S_IXUSR & buf.st_mode && ft_strcmp(argv[0], fil->d_name) == 0)
		{
			do_it(tmp2, argv, vne);
			ft_strdel(&tmp2);
			closedir(op);
			return (1);
		}
		ft_strdel(&tmp2);
	}
	closedir(op);
	return (0);
}
