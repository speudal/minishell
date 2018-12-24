/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:43:01 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 01:57:22 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	**get_path(char **vne)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = 0;
	while (ft_strcmp(tmp, "PATH=") && vne[i])
	{
		ft_strdel(&tmp);
		if (!(tmp = ft_strsub(vne[i], 0, 5)))
			return (0);
		if (ft_strcmp(tmp, "PATH="))
			i++;
	}
	ft_strdel(&tmp);
	return (vne[i] ? ft_strsplit((vne[i]) + 5, ':') : 0);
}
