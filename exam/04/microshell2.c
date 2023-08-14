#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// test => https://github.com/Glagan/42-exam-rank-04/blob/master/microshell/test.sh*/

// #ifdef TEST_SH
// # define TEST		1
// #else
// # define TEST		0
// #endif

int	print_error(char *message, char *argv)
{
	while (*message)
		write(2, message++, 1);
	if (argv)
		while (*argv)
			write(2, argv++, 1);
	write(2, "\n", 1);
	return (1);
}

int	exec_cmd(char **argv, int i, int temp_fd, char **envp)
{
	dup2(temp_fd, 0);
	close(temp_fd);
	argv[i] = NULL;
	if (execve(argv[0], argv, envp) == -1)
		return (print_error("error: cannot execute ", argv[0]));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	temp_fd;
	int	fd[2];

	(void)argc;
	i = 0;
	temp_fd = dup(0);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				print_error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				print_error("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (exec_cmd(argv, i, temp_fd, envp))
					return (1);
			}
			else
			{
				close(temp_fd);
				while (waitpid(-1, 0, WUNTRACED) != -1)
					;
				temp_fd = dup(0);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (exec_cmd(argv, i, temp_fd, envp))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(temp_fd);
				temp_fd = fd[0];
			}
		}
	}
	close(temp_fd);
	// if (TEST)
	// 	while (1);
	return (0);
}