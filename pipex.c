#include "pipex.h"

void	child_proc(char **argv,char **envp, int *fd)
{
	int fd_file1;

	fd_file1 = open(argv[1], O_RDONLY);
	if (fd_file1 == -1)
		error();
	dup2(fd_file1, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	char *cmd;
	
	execve(cmd, argv[2], envp);
}

void	parent_proc(char **argv,char **envp, int *fd)
{
	int fd_file2;
	fd_file2(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);

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
		if (id == 0)
			child_proc(argv, envp, fd);
		wait(NULL);
		parent_proc(argv, envp, fd);

	}
	else
	{
		perror("Error");
	}
	return 0;
}