/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:02:50 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/14 17:47:05 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_one(char **argv, int end[2], t_list *ag, char **envp)
{
	int		i;
	int		f1;
	char	*cmd;

	f1 = open(argv[1], O_RDONLY, 0644);
	if (f1 < 0)
		ft_putstr_fd("Error Openning File\n", 1);
	i = -1;
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(f1);
	close(end[0]);
	close(end[1]);
	while (ag->my_path[++i])
	{
		cmd = ft_strjoin(ag->my_path[i], "/");
		cmd = ft_strjoin(cmd, ag->my_cmd[0]);
		execve(cmd, ag->my_cmd, envp);
		free(cmd);
	}	
	perror("Error");
	exit(1);
}

void	child_two(t_list *ag, int end[2], char **argv, char **envp)
{
	char	*cmd;
	int		i;
	int		f2;

	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f2 < 0)
		ft_putstr_fd("Error Openning file\n", 1);
	i = -1;
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	dup2(f2, STDOUT_FILENO);
	close(f2);
	close(end[1]);
	while (ag->my_path[++i])
	{
		cmd = ft_strjoin(ag->my_path[i], "/");
		cmd = ft_strjoin(cmd, ag->cmd_two[0]);
		execve(cmd, ag->cmd_two, envp);
		free(cmd);
	}
	perror("Error");
	exit(1);
}
