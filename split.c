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

static	int	calc_num(const char *s, char c)
{
	int	count;
	int	mot;
	int	i;

	count = 0;
	i = 0;
	mot = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			mot = 0;
		else if (mot == 0)
		{
			mot = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static	int	long_mot(char *s, int j, char c)
{
	int	len;

	len = 0;
	while (s[j] != c && s[j] != '\0')
	{
		len++;
		j++;
	}
	return (len);
}

static	void	*fr_ee(char **mots, int j)
{
	while (j--)
		free(mots[j]);
	free(mots);
	return (NULL);
}

static	char	**help(const char *s, char c, char **mots)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (j < calc_num(s, c))
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		mots[j] = (char *)malloc(sizeof(char) *(long_mot((char *)s, i, c) + 1));
		if (!mots[j])
			return (fr_ee(mots, j));
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			mots[j][k++] = s[i];
			i++;
		}
		mots[j++][k] = '\0';
	}
	mots[j] = 0;
	return (mots);
}

char	**ft_split(char const *s, char c)
{
	char	**mots;

	if (!s)
		return (NULL);
	mots = malloc(sizeof(char *) * (calc_num(s, c) + 1));
	if (!mots)
		return (NULL);
	return (help(s, c, mots));
}
