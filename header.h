/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:27 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/12 13:34:33 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct s_list 
{
    char *path_envp;
    char **my_path;
    char **my_cmd;
    char **cmd_two;
} t_list;


size_t	ft_strlen(const char *s);
void	pipex(int f1, int f2, t_list ag, char **argv);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*find_path(char  **envp);
int		comp_str(char *str1, char *str2);
void	child_one(int f1, char **argv, int end[2], t_list ag);
void	child_two(int f2, char **cmd_two);
char	*ft_strjoin(char const *s1, char const *s2);

#endif