/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 03:46:51 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 03:47:36 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static void	split(char **ret, int i, t_env *envi)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(envi->var, "=")))
		return ;
	if (!(ret[i] = ft_strjoin(tmp, envi->val)))
		return ;
	ft_strdel(&tmp);
}

char		**copy_env(t_env *envi)
{
	t_env	*or;
	int		i;
	char	**ret;

	i = 0;
	or = envi;
	while (envi)
	{
		i++;
		envi = envi->next;
	}
	if (!(ret = (char **)malloc(sizeof(char *) * i + 1)))
		return (0);
	ret[i] = 0;
	i = 0;
	envi = or;
	while (envi)
	{
		split(ret, i, envi);
		envi = envi->next;
		i++;
	}
	return (ret);
}
