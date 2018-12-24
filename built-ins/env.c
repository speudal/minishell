/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:19:34 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 02:31:17 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "minishell.h"
#include "libft.h"

int		bi_env(char **argv, t_env *cpy)
{
	int			i;
	pid_t		t;

	i = 0;
	if (argv[1])
	{
		if (argv[2] && ft_strequ(argv[1], "-i"))
		{
			t = fork();
			if (t == 0)
				execve(argv[2], argv, 0);
			else if (t > 0)
				t = wait(0);
			else if (t == -1)
				ft_printf("Couldn't fork on %s.\n", argv[1]);
		}
		else
		{
			ft_putendl("env: usage: env -i [command]");
			return (1);
		}
	}
	else
	{
		while (cpy)
		{
			ft_putstr(cpy->var);
			ft_putchar('=');
			ft_putstr(cpy->val);
			ft_putchar('\n');
			cpy = cpy->next;
			i++;
		}
	}
	return (1);
}
