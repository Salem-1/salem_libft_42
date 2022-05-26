/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:07:36 by ahsalem           #+#    #+#             */
/*   Updated: 2022/05/24 20:12:45 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*word_data(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		*all_data;
	int		i;
	int		j;
	
	if (!*s)
	{
		arr = malloc(1);
		arr[0] = NULL;
		return (arr);;
	}
	i = 0;
	
	all_data = word_data(s, c);
	
	i = 0;
	arr = (char **)malloc(sizeof(char *) * all_data[i] + 1);
	 if(!all_data[0])
	 {
		 
		 arr[0] = NULL;
		 free(all_data);	 
		 return(arr);
	 }
	 
	if (!arr)
	{	
		free(all_data);
		return (NULL);
	}
	i ++;
	j = 0;
	while(j  < all_data[0])
	{
		arr[j] = ft_substr(s, all_data[i],(all_data[i + 1] - all_data[i]));
		j++;
		i += 2;
	}
	free(all_data);
	arr[j] = NULL;
	return (arr);
}

static int	*word_data(char const *s, char c)
{
	int	i;
	int word_counter;
	int	*arr;
	int j;
	
	i = 0;
	j = 1;  
	word_counter = 0;
	if (s[i] != c)
	{
		word_counter++;
	}
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1]))
			word_counter++;
		i++;
	}
	arr = malloc(sizeof(int) * (word_counter * 2) + 1); 
	if (!arr)
		return (NULL);
	i = 0;
	arr[0] = word_counter;
	if (s[0] != c) //if the beging of the string not the separator
	{	
		arr[j] = 0;
		j++;
	}
	
	while (s[i])
	{
		if ((s[i] == c && (s[i + 1] != c) && s[i + 1])) 
		{
			arr[j] = i + 1;
			j++;	
		}
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			arr[j] = i + 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < arr[0] * 2 + 1)
	{
		i++;
	}
	return (arr);
}
/*
//you can even create a function to handle the outliars cases, why not?

22nd May 2022- Tommorrow inshalla will split the split.

Ahmed Salem
42 Abu Dhabi
*/

/*
static int	*splitters(char const *s, char c);
static int	split_size(char const *s, char c);
static int	splitter_helper(char const *s, int i, char c, int splitter);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		last;


	//define  an int* splitter = splitters(c,s); then free it at the end of the program; free(splitter)
	
	i = 0;
	arr = (char **)malloc(sizeof(char *) * splitters(s, c)[0] + 2);
	if (arr == NULL)
		return (NULL);
	while (i < splitters(s, c)[0])
	{
		last = split_size(&s[splitters(s, c)[i + 1] + 1], c);
		arr[i] = malloc(sizeof(char) * (last + 3));
		arr[i] = ft_substr(s, splitters(s, c)[i + 1],
				sizeof(char *) * last + 2);
		arr[i][last + 1] = '\0';
		i++;
	}
	
	arr[i] = NULL;
	return (arr);
}

int	*splitters(char const *s, char c)
{
	int	i;
	int	splitter;
	int	*arr;

	i = 0;
	splitter = 0;
	if (*s != c)
		splitter = 1;
	splitter = splitter_helper(s, i, c, splitter);
	arr = malloc(sizeof(int) * splitter + 1);
	arr[0] = splitter;
	arr[1] = 0;
	splitter = 2;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1]))
		{
			arr[splitter] = i + 1 ;
			splitter++;
		}
		i++;
	}
	return (arr);
}

static int	split_size(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
		size++;
	}
	return (size);
}

static int	splitter_helper(char const *s, int i, char c, int splitter)
{
	//add condtion if the fir
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1]))
			splitter++;
		i++;
	}
	return (splitter);
}

*/
// function that takes string and del. and return int
// while loop ---> loop over each char, 
//number of spaces + condiutino for the starting without delimiter
//function to count the next word to malloc 