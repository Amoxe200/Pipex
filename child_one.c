/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:02:50 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/12 22:55:44 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_one(int f1, char **argv, int end[2], t_list *ag, char **envp)
{
		int i;
		char *cmd;
		
		i = -1;
		dup2(f1, STDIN_FILENO);
	    dup2(end[1], STDOUT_FILENO);
		(void)argv;
		// int d;
		
		// d = 0;
		// while (ag->path_envp[d])
		//{
			dprintf(2,"[%s\n]", ag->path_envp);
			//d++;
		//}
		
		while (ag->my_path[++i])
		{
			cmd = ft_strjoin(ag->my_path[i], "/");
			//dprintf(2,"AG COM ::%s\n", ag->my_cmd[0]);
			cmd = ft_strjoin(cmd, ag->my_cmd[0]);
			dprintf(2, "[cmd child 1 = %s]\n", cmd);
			//dprintf(2,"commade child 1 = %s\n", ag->my_cmd[2]);
			//dprintf(2,"commade second child 1 = %s\n", ag->my_cmd[1]);
			execve(cmd, ag->my_cmd, envp);
			free(cmd);
		}		
        // execvp(ag->my_cmd[0],ag->my_cmd);	
}

void	child_two(int f2, t_list *ag, int end[2], char **argv, char **envp)
{
	int i;
	char *cmd;
	
	i = -1;
	dup2(end[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);

	(void)argv;
	while (ag->my_path[++i])
	{
		cmd = ft_strjoin(ag->my_path[i], "/");
		cmd = ft_strjoin(cmd, ag->cmd_two[0]);
		dprintf(2,"[child 1 cmd = %s]\n", cmd);
		execve(cmd, ag->cmd_two, envp);
		free(cmd);
	}
    
}