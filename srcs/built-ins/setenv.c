/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:32:53 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 03:36:07 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "minishell.h"

int		bi_setenv(char **argv)
{
	extern char	**environ;
	int			i;

	i = 0;
	if (!(argv[1]))
		return (bi_env(argv));
	while (environ[i])
		i++;
	environ[i] = ft_strdup(ft_strjoin(ft_strjoin(argv[1], "="), argv[2]));
	return (1);
}
