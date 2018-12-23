/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:19:34 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 22:31:19 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int		bi_env(char **argv, t_env *cpy)
{
	int			i;

	i = 0;
	argv++;
	while (cpy)
	{
		ft_putstr(cpy->var);
		ft_putchar('=');
		ft_putstr(cpy->val);
		ft_putchar('\n');
		cpy = cpy->next;
		i++;
	}
	return (1);
}
