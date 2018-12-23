/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:32:53 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 22:36:37 by tduval           ###   ########.fr       */
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

int			bi_setenv(char **argv, t_env *envi)
{
	if (!argv[1])
		return (bi_env(argv, envi));
	else if (ct_args(argv) != 3)
	{
		ft_putendl("setenv: usage: setenv [VARIABLE] [VALUE]");
		return (1);
	}
	while (envi->next && ft_strequ(envi->var, argv[1]) == 0)
		envi = envi->next;
	if (ft_strequ(envi->var, argv[1]))
	{
		ft_strdel(&envi->val);
		if (!(envi->val = ft_strdup(argv[2])))
			return (1);
	}
	else
	{
		if (!(envi->next = (t_env *)malloc(sizeof(t_env))))
			return (1);
		if (!(envi->next->var = ft_strdup(argv[1])))
			return (1);
		if (!(envi->next->val = ft_strdup(argv[2])))
			return (1);
		envi->next->next = 0;
	}
	return (1);
}
