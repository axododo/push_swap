/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguilber <mguilber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:05:19 by mguilber          #+#    #+#             */
/*   Updated: 2026/03/29 17:10:03 by mguilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[0] && s[0] != c)
		count++;
	while (s[++i])
		if (s[i] != c && s[i - 1] == c)
			count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = malloc(sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = 0;
		return (dest);
	}
	size = ft_strlen(s) - start;
	if (size > len)
		size = len;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, &s[start], (size + 1));
	return (dest);
}

static void	*ft_free(char **w, size_t j)
{
	while (j--)
		free(w[j]);
	free(w);
	return (NULL);
}

static size_t	ft_next_word(char const *s, char c, size_t i, char **w)
{
	size_t	start;

	while (s[i] && s[i] == c)
		i++;
	start = i;
	while (s[i] && s[i] != c)
		i++;
	*w = ft_substr(s, start, i - start);
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**w;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	w = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!w)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		i = ft_next_word(s, c, i, &w[j]);
		if (!w[j])
			return (ft_free(w, j));
		j++;
	}
	w[j] = NULL;
	return (w);
}
