/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:19:34 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 02:21:27 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		bi_env(char **argv)
{
	extern char	**environ;
	int			i;

	i = 0;
	argv++;
	while (environ[i])
	{
		ft_putendl(environ[i]);
		i++;
	}
	return (1);
}
