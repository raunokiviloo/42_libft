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

int	ft_memcmp(const void *str1, const void *str2, size_t bytestocheck)
{
	if (bytestocheck == 0)
		return (0);
	while (bytestocheck-- > 0)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (str1 - str2);
}
//Differs from strncmp because memcmp does not stop at \0.
