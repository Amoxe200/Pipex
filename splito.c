/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:22:13 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/08 17:30:12 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

static int	calc_words(char *s, char c)
{
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j = 1;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
		if (j == 1)
			count++;
	}
	return (count);
}

static int	calc_char(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		s++;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	int j;

	j = 0;
	while (j <= i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (str);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	int		j;
	char	**str;

	i = 0;
	if (!s)
		return (0);
	words = calc_words((char*)s, c);
	if ((str = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (str);
	while (i < words)
	{
		j = 0;
		str[i] = (char*)malloc(sizeof(char) * (calc_char((char*)s, c) + 1));
		if (!str[i])
			return (ft_free(str, i));
		while (s[0] == c && s[0] != '\0')
			s++;
		while (s[0] != c && s[0] != '\0')
			str[i][j++] = *s++;
		str[i++][j] = '\0';
	}
	str[i] = 0;
	printf("\n%s\n", str[0]);
	printf("\n%s\n", str[1]);
	return (str);
}
