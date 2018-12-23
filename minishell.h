/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:35:59 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 02:32:27 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

typedef struct	stat		t_stat;
typedef struct	dirent		t_dirent;

char			**get_path(void);
int				act_prog(char *path, char **argv);
void			free_split(char **argv);
int				hub(char **argv);
int				bi_env(char **argv);
int				bi_setenv(char **argv);
int				bi_echo(char **argv);

#endif
