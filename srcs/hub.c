/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:31:58 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 22:31:00 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static int	path_prog(char **argv)
{
	int		i;
	char	**path;

	i = 0;
	if (!(path = get_path()))
	{
		ft_putstr("error : PATH variable not found.\n");
		return (0);
	}
	while (path[i] && !(act_prog(path[i], argv))) 
		i++;
	i = path[i] ? 1 : 0;
	free_split(path);
	return (i);
}

static int	local_command(char **argv)
{
	pid_t		new;
	int			status;
	extern char	**environ;
	t_stat		buf;

	lstat(argv[0], &buf);
	if (S_IXUSR & buf.st_mode)
	{
		new = fork();
		if (new == 0)
			execve(argv[0], argv, environ);
		else if (new > 0)
			new = wait(&status);
		return (1);
	}
	return (0);
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
		return (1);
	else if (ft_strequ(argv[0], "cd"))
		return (bi_cd(argv));
	else if (ft_strequ(argv[0], "exit"))
		exit (0); //oublie pas de free
	else if (path_prog(argv))
		return (1);
	else if (local_command(argv))
		return (1);
	return (0);
}
