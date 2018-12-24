/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:19:34 by tduval            #+#    #+#             */
/*   Updated: 2018/12/24 04:10:15 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "minishell.h"
#include "libft.h"

static void	arg_case(char **argv)
{
	pid_t		t;

	if (argv[1] && ft_strequ(argv[1], "-i"))
	{
		t = fork();
		if (t == 0)
			execve(argv[2], argv + 2, 0);
		else if (t > 0)
			t = wait(0);
		else if (t == -1)
			ft_printf("Couldn't fork on %s.\n", argv[1]);
	}
	else
		ft_putendl("env: usage: env -i [command]");
}

int			bi_env(char **argv, t_env *cpy)
{
	int			i;

	i = 0;
	if (argv[1])
		arg_case(argv);
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
