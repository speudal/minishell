/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_enval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 00:16:39 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 00:50:01 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

void	ch_enval(t_env *envi, char *vari, char *valu)
{
	while (envi && ft_strequ(envi->var, vari) == 0)
		envi = envi->next;
	if (envi)
	{
		free(envi->val);
		envi->val = ft_strdup(valu);
	}
}
