/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:02:50 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/13 20:07:14 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_one(int f1, char **argv, int end[2], t_list *ag, char **envp)
{
		int i;
		char *cmd;
		
    	f1 = open(argv[1], O_RDONLY, 0644);
		i = -1;
		dup2(f1, STDIN_FILENO);
	    dup2(end[1], STDOUT_FILENO);
		close(f1);
		close(end[0]);
		close(end[1]);
		(void)argv;
		while (ag->my_path[++i])
		{
			cmd = ft_strjoin(ag->my_path[i], "/");
			cmd = ft_strjoin(cmd, ag->my_cmd[0]);
			execve(cmd, ag->my_cmd, envp);
			free(cmd);
		}	
			perror("sidi  za3im");
			exit(1);
}

void	child_two(int f2, t_list *ag, int end[2], char **argv, char **envp)
{
	int i;
	char *cmd;
    f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	i = -1;
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	(void)argv;
	dup2(f2, STDOUT_FILENO);
	close(f2);
	close(end[1]);
	(void)argv;
	while (ag->my_path[++i])
	{
		cmd = ft_strjoin(ag->my_path[i], "/");
		cmd = ft_strjoin(cmd, ag->cmd_two[0]);
		execve(cmd, ag->cmd_two, envp);
		free(cmd);
	}
	perror("sidi  za3im");
	exit(1);
}