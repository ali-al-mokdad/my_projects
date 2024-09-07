/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:52:05 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/03 19:03:52 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"
#include "./../lib/get_next_line/get_next_line.h"
#include "./../lib/ft_printf/libft/libft.h"

int	help(int *fd, char **argv, char **envp)
{
	int	file;

	file = open(argv[1], O_RDONLY, 0777);
	if (file == -1)
	{
		perror("Error");
		exit(-1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	execute(argv[2], envp);
	return (3);
}

void	child_process_bonus(int *fd, int argc, char **argv, char **envp)
{
	int		file;
	int		i;
	char	*str;
	int		dd;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		file = open("here_doc.temp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dd = open("/dev/tty", O_WRONLY);
		dup2(dd, STDOUT_FILENO);
		ft_printf("pipe heredoc> ");
		str = get_next_line(0);
		dup2(file, STDOUT_FILENO);
		ft_printf("%s", str);
		while (ft_strncmp(str, argv[2], ft_strlen(argv[2])))
		{
			dup2(dd, STDOUT_FILENO);
			ft_printf("pipe heredoc> ");
			dup2(file, STDOUT_FILENO);
			str = get_next_line(0);
			ft_printf("%s", str);
		}
		close (dd);
	}
	else
		i = help(fd, argv, envp);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	execute(argv[i], envp);
	while (i++ < argc - 2)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		execute(argv[i], envp);
	}
}

void	parent_process_bonus(int *fd, int argc, char **argv, char **envp)
{
	int	file;

	file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_printf("%s", argv[argc - 1]);
	exit (0);
	if (file == -1)
	{
		perror("Error");
		exit(-1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[argc - 2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (perror("Error"), 0);
	pid = fork();
	if (pid == -1)
		return (perror("Error"), 0);
	if (pid == 0)
		child_process_bonus(fd, argc, argv, envp);
	wait(NULL);
	parent_process_bonus(fd, argc, argv, envp);

	return (0);
}
