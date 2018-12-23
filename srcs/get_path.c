/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:43:01 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 00:53:39 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	**get_path(void)
{
	extern char	**environ;
	int			i;
	char		*tmp;

	i = 0;
	tmp = 0;
	while (ft_strcmp(tmp, "PATH=") && environ[i])
	{
		ft_strdel(&tmp);
		if (!(tmp = ft_strsub(environ[i], 0, 5)))
			return (0);
		if (ft_strcmp(tmp, "PATH="))
			i++;
	}
	ft_strdel(&tmp);
	return (environ[i] ? ft_strsplit((environ[i]) + 5, ':') : 0);
}
