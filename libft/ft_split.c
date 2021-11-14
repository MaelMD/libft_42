/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:08:01 by mmohamme          #+#    #+#             */
/*   Updated: 2021/11/14 19:42:15 by mmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	flage;
	int	cp;

	i = 0;
	flage = 0;
	cp = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && flage == 0)
		{
			cp++;
			flage = 1;
		}
		else if (s[i] == c && flage == 1)
			flage = 0;
		i++;
	}
	return (cp);
}

int	ft_count_and_alloc(char *s, char c)
{
	int	i;
	int	cp;

	i = 0;
	cp = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		cp++;
	}
	if (cp == 0)
		return (0);
	return (cp);
}

int	ft_split_2(char const *s, char c, char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			k = 0;
			str[j] = (char *)malloc(ft_count_and_alloc((char *)&s[i], c) + 1);
			if (!str[j])
				return (j);
			while (k < ft_count_and_alloc((char *)&s[i], c))
			{
				str[j][k] = s[i + k];
				k++;
			}
			str[j++][k] = 0;
			i += k;
		}
	}
	str[j] = 0;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	str = (char **)malloc(sizeof(char *) * count_word(s, c) + 1);
	if (!str)
		return (NULL);
	j = ft_split_2(s, c, str);
	if (j != -1)
	{
		while (j >= 0)
		{
			free(str[j]);
			j--;
		}
		free(str);
	}
	return (str);
}