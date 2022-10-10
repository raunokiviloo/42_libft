/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:44 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	const char	*originaldst;
	const char	*originalsrc;
	size_t		dstlen;
	size_t		srclen;
	size_t		bytestowrite;

	originaldst = dst;
	originalsrc = src;
	bytestowrite = dsize;
	while (bytestowrite-- && *dst++)
		;
	dstlen = dst - originaldst;
	bytestowrite = dsize - dstlen;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (!bytestowrite--)
		return (dstlen + srclen);
	while (*src)
		if (bytestowrite--)
			*dst++ = *src++;
	*dst = '\0';
	return (dstlen + (src - originalsrc));
}
