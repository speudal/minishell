/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:35:59 by tduval            #+#    #+#             */
/*   Updated: 2018/12/23 23:15:26 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

typedef struct 				s_env
{
	char					*var;
	char					*val;
	struct s_env			*next;
}							t_env;

typedef struct	stat		t_stat;
typedef struct	dirent		t_dirent;

char						**get_path(void);
char						**arg_repl(char **argv, t_env *envi);
char						*get_enval(t_env *envi, char *target);
t_env						*get_env(void);
int							act_prog(char *path, char **argv);
void						free_split(char **argv);
int							hub(char **argv, t_env *envi);
int							bi_env(char **argv, t_env *cpy);
int							bi_setenv(char **argv, t_env *envi);
int							bi_unsetenv(char **argv, t_env *envi);
int							bi_echo(char **argv);
int							bi_cd(char **argv, t_env *envi);

#endif
