/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:57:44 by nozakoya          #+#    #+#             */
/*   Updated: 2021/08/22 16:57:47 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void proc(char **cmd, char **envp)
{
	char *cmd_name;
	if (cmd[0][0] == '/')
	{
		cmd_name = cmd[0];
		execve(cmd_name, cmd, envp);
	}
	else
	{
		int i;
		char *pointer;
		char **path = NULL;
		i = 0;
		while(envp[i])
		{
			if (!ft_strncmp(envp[i], "PATH", 4))
			{
				path = ft_split(envp[i] + 5, ':');
				break;
			}
			++i;
		}
		i = 0;
		while(path[i])
		{
			pointer = ft_strjoin(path[i], "/");
			cmd_name = ft_strjoin(pointer, cmd[0]);
			execve(cmd_name, cmd, envp);
			free(pointer);
			free(cmd_name);
			++i;
		}
	}
}

void	child_proc(char **argv, char **envp, int *fd)
{
	int fd_file1;
	char **cmd;
	fd_file1 = open(argv[1], O_RDONLY);
	close(fd[0]);
	if(fd_file1 == -1)
		error();
	dup2(fd_file1, 0);
	dup2(fd[1], 1);
	cmd = ft_split(argv[2], ' ');
	proc(cmd, envp);
	wait(NULL);
}

void	parent_proc(char **argv, char **envp, int *fd)
{
	int fd_file2;
	char **cmd;
	fd_file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if(fd_file2 == -1)
		error();
	dup2(fd[0], 0);
	dup2(fd_file2, 1);
	close(fd[1]);
	cmd = ft_split(argv[3], ' ');
	proc(cmd, envp);
}
int main(int argc, char **argv, char **envp)
{
	int fd[2];
	int id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
				error();
		id = fork();
		if(id == -1)
				error();
		if(id == 0)
			child_proc(argv, envp, fd);
		else
		{
			wait(NULL);
			parent_proc(argv, envp, fd);
		}
		close(fd[0]);
		close(fd[1]);
	}
	else
		error();
	return 0;
}