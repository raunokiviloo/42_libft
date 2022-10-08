/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:45 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:45 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*substring_index;

	if (!s || len == 0 || start + 1 > ft_strlen(s))
		return (NULL);
	substring = malloc(sizeof(*substring) * len);
	if (!substring)
		return (NULL);
	substring_index = substring;
	while (len-- > 1 && s[start])
		*substring_index++ = s[start++];
	*substring_index = '\0';
	return (substring);
}
// Does len include \0?
// Do we nullterminate - assume yes, since it is a subSTRING.
// If start == 1, do we start from 0th or 1st element?
// Peep the malloc syntax - I like it! Works with all types.
// Did errorhandling for - s points to NULL; len = 0; start outside s. 
