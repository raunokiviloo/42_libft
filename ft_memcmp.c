/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:44 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t bytestocheck)
{
	char	*string1;
	char	*string2;

	string1 = (char *)str1;
	string2 = (char *)str2;
	if (bytestocheck == 0)
		return (0);
	while (bytestocheck-- > 0)
	{
		if (*string1 != *string2)
			break ;
		string1++;
		string2++;
	}
	return (string1 - string2);
}
//Differs from strncmp because memcmp does not stop at \0.
