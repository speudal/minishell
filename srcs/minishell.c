/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:09:32 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 23:59:01 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <minishell.h>
#include "libft.h"

static char	*no_tab(char *com)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_strnew(ft_strlen(com) + 1)))
		return (0);
	while (com[i])
	{
		if (com[i] != '\t')
			ret[i] = com[i];
		else
			ret[i] = ' ';
		i++;
	}
	return (ret);
}

static void	free_env(t_env	*envi)
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

int			main(void)
{
	t_env	*envi;
	char	*com;
	char	*tmp;
	char	**argv;

	com = 0;
	argv = 0;
	if (!(envi = get_env()))
		return (0);
	while (69)
	{
		write(1, "\033[1;31m$> \e[39m", 16);
		com = 0;
		if (get_next_line(1, &com))
		{
			if (!(tmp = no_tab(com)))
				return (0);
			if (!(argv = ft_strsplit(tmp, ' ')))
				return (0);
			if (!(argv = arg_repl(argv, envi)))
				return (0);
			if (argv[0])
				if (!(hub(argv, envi)))
					ft_printf("minishell: %s: command not found.\n", argv[0]);
			free_split(argv);
			ft_strdel(&com);
			ft_strdel(&tmp);
		}
		else
			ft_putchar('\n');
	}
	free_env(envi);
	return (0);
}
