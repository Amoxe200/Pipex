/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:24 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/14 17:58:00 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parser(char **argv, char **envp, t_list *ag)
{
	ag->path_envp = find_path(envp);
	ag->my_path = ft_split(ag->path_envp, ':');
	ag->my_cmd = ft_split(argv[2], ' ');
	ag->cmd_two = ft_split(argv[3], ' ');
}

int	main(int ac, char **argv, char **envp)
{
	pid_t	child1;
	pid_t	child2;
	int		end[2];
	int		status;
	t_list	ag;	

	pipe(end);
	if (ac != 5)
	{
		ft_putstr_fd("Too Many args\n", 1);
		exit(1);
	}
	parser(argv, envp, &ag);
	child1 = fork();
	if (child1 == 0)
		child_one(argv, end, &ag, envp);
	close(end[1]);
	child2 = fork();
	if (child2 == 0)
		child_two(&ag, end, argv, envp);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	return (0);
}
