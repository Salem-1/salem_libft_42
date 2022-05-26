/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:07:44 by ahsalem           #+#    #+#             */
/*   Updated: 2022/05/16 16:38:18 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		*result;
	size_t	i;

	i = 0;
	result = malloc(size * count);
	while (i < count)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
