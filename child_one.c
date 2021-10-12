/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:02:50 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/11 17:08:36 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_one(int f1, char *cmd_one)
{
	(void)f1;
	printf("First command = %s\n", cmd_one);
}

void	child_two(int f2, char *cmd_two)
{
	(void)f2;	
	printf("Second Command = %s\n", cmd_two);	
}