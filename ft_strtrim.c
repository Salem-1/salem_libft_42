/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:28:29 by ahsalem           #+#    #+#             */
/*   Updated: 2022/05/22 15:01:03 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char const *s, char const *set);
static void	*copier(char const *s1);
static int	starter(const char *s1, const char *set, int flag);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;

	if (set == NULL)
		return ((char *)copier(s1));
	if (!s1)
		return ("\0");
	start = starter(s1, set, 0);
	end = starter(s1, set, 1);
	if (start > end || start == ft_strlen(s1) -1)
	{
		trimmed = malloc(sizeof(char) * (1));
		*trimmed = '\0';
	}
	else
	{
		trimmed = malloc(sizeof(char) * (end - start + 1));
		ft_strlcpy(trimmed, &s1[start], end - start + 2);
	}
	if (!trimmed)
		return (NULL);
	return (trimmed);
}

static int	check_char(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (*s == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	*copier(char const *s1)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * ft_strlen(s1));
	return (memcpy(copy, s1, ft_strlen(s1)));
}

static int	starter(const char *s1, const char *set, int flag)
{
	int	index;

	if (!flag)
	{
		index = 0;
		while (index < ft_strlen((char *)s1))
		{
			if (!check_char(&s1[index], set))
				break ;
			index++;
		}
	}
	else
	{
		index = ft_strlen(s1) - 1;
		while (index > 0)
		{
			if (!check_char(&s1[index], set))
				break ;
			index--;
		}
	}
	return (index);
}
