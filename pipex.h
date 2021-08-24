/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:57:52 by nozakoya          #+#    #+#             */
/*   Updated: 2021/08/22 16:57:53 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void            error(void);
void            child_proc(char **argv, char **envp, int *fd);
void            parent_proc(char **argv, char **envp, int *fd);
size_t          ft_strlen(const char *s);
char            **ft_split(char const *s, char c);
char	        *ft_strjoin(char *s1, char *s2);
int	            ft_strncmp(const char *s1, const char *s2, size_t n);
void            proc(char **cmd, char **envp);

#endif