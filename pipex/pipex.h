/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:47:11 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/31 16:29:29 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define    PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./lib/ft_printf/ft_printf.h"

void	execute(char *argv, char **envp);
void	error(void);
void	child_process_bonus(int *fd, int argc, char **argv, char **envp);
void	parent_process_bonus(int *fd, int argc, char **argv, char **envp);

#endif
