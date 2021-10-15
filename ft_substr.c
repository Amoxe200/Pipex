/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:28:12 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/09 15:30:38 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	p = malloc(len + 1);
	if (p == NULL)
		return (0);
	while (len--)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return ((char *)(p));
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}
