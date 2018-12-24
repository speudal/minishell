/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:54:32 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 22:57:17 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*get_enval(t_env *envi, char *target)
{
	while (envi && ft_strcmp(envi->var, target))
		envi = envi->next;
	return (envi ? ft_strdup(envi->val) : 0);
}
