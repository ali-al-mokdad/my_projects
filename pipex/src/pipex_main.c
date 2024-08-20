/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:50:18 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/20 17:14:47 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void iprsreturnerror(int pipefd)
{
	if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close the write end
        dup2(pipefd[0], STDIN_FILENO);  // Redirect stdin to the read end of the pipe
        close(pipefd[0]);

        execlp("cat", "cat", NULL);  // Example command
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        close(pipefd[0]);  // Close the read end
        dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to the write end of the pipe
        close(pipefd[1]);

        execlp("ls", "ls", NULL);  // Example command
        perror("execlp");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{	
	int	i;
	int	pipefd[2];
	int	fd_in;

	if (argc < 4)
	{
		fprintf(stderr, "Usage: %s <cmd1> <cmd2> ... <cmdN>\n", argv[0]);
		return (1);
	}
	fd_in = 0;
	i = 1;
	while (i < argc - 1)
	{
		pipe(pipefd);

		if (fork() == 0)
		{
			dup2(fd_in, 0);
			if (i < argc - 2)
				dup2(pipefd[1], 1);
			close(pipefd[0]);
			execvp(argv[i], &argv[i]);
			perror("execvp");
			exit(1);
		}
		else
		{
			wait(NULL);
			close(pipefd[1]);
			fd_in = pipefd[0];
			i++;
		}
	}
	dup2(fd_in, 0);
	execvp(argv[i], &argv[i]);
	perror("execvp");
	return (1);
}
