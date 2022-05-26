/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:16:01 by ahsalem           #+#    #+#             */
/*   Updated: 2022/05/21 10:28:24 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(initial dst) + strlen(src); if retval >= siz,
 * truncation occurred.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = (size_t)ft_strlen(dst);
	if (dstsize == 0)
		return ((size_t)ft_strlen(src));
	while (src[n] && ((n + i) < dstsize - 1))
	{
		dst[i + n] = src[n];
		n++;
	}
	if (dstsize < (size_t)ft_strlen(dst))
		return (dstsize + (size_t)ft_strlen(src));
	dst[i + n] = '\0';
	return (i + (size_t)ft_strlen(src));
}
