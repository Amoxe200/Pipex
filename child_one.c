/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:02:50 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/12 18:36:19 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_one(int f1, char **argv, int end[2], t_list ag)
{
	int i;
	char *cmd;
	
	i = -1;

	
	// dup2(f1, STDIN_FILENO);
	// dup2(end[1], STDOUT_FILENO);

	while (ag.my_path[i])
	{
		// dprintf(2, "1asdhasda\n");
		dprintf(2, "path = %s argv = %s\n", ag.my_path[i], argv[2]);
		printf("lmao\n");
		cmd = ft_strjoin(ag.my_path[i], "/");
		cmd = ft_strjoin(cmd, argv[2]);
		dprintf(2, "2adaadasda %s\n", cmd);
		int fd = open(cmd, O_RDONLY, 0644);
		dprintf(2, "fd = %d\n", fd);
		if (fd > 0)
			{
				dprintf(2,"Success\n");
				dprintf(2,"%s\n", cmd);
			}	
			i++;
	}
	dprintf(2,"adadaad\n");
	// close(end[0]);
	// close(f1);
	(void) end[0];
	(void) f1;
}

void	child_two(int f2, char **cmd_two)
{
	(void)f2;
	(void)cmd_two;	
}