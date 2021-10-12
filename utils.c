/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:29:23 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/12 13:29:59 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int comp_str(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str2[i])
    {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    return (1);
}

char *find_path(char  **envp)
{
    int d;
    char *str;
    char *path;
    
    d = 0;
    while (envp[d])
    {
        str = envp[d];
        if (ft_strlen(str) >= 5 && comp_str(str, "PATH="))
                path = str;
        d++;
    }
    return (path);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	i = 0;
	p = malloc(sizeof(char *) * (l1 + ft_strlen(s2)));
	if (p == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		p[i + l1] = s2[i];
		i++;
	}
	p[i + l1] = '\0';
	return (p);
}