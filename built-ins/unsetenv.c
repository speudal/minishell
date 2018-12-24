/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:40:56 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 02:51:54 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static int	ct_args(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int			bi_unsetenv(char **argv, t_env *envi)
{
	t_env	*prev;

	if (ct_args(argv) != 2)
	{
		ft_putendl("unsetenv: usage: unsetenv [VARIABLE]");
		return (1);
	}
	while (envi && ft_strequ(envi->var, argv[1]) == 0)
	{
		prev = envi;
		envi = envi->next;
	}
	if (envi)
	{
		prev->next = envi->next;
		ft_strdel(&envi->val);
		ft_strdel(&envi->var);
		free(envi);
	}
	return (1);
}
