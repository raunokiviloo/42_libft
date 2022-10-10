/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:45 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:45 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack,
const char *needle, size_t bytestocheck)
{
	const char	*originalneedle;
	const char	*potentialmatch;

	if (!needle)
		return ((char *)haystack);
	originalneedle = needle;
	while (*haystack && bytestocheck-- > 0)
	{
		if (*haystack == *needle)
		{	
			potentialmatch = haystack;
			while (*haystack++ == *needle++)
				if (!needle)
					return ((char *)potentialmatch);
			needle = originalneedle;
			haystack = potentialmatch;
		}
		haystack++;
	}
	return (NULL);
}
