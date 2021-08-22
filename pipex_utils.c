#include "pipex.h"

void error(void)
{
	perror ("Error");
	exit (EXIT_FAILURE);
}