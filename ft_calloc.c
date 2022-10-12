/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:43 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:43 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*arr;
	size_t	max_size;

	max_size = -1;
	if (max_size / nelem <= elsize)
		return (NULL);
	arr = malloc(nelem * elsize);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nelem * elsize);
	return (arr);
}
//Need to initialize to 0.
//Need to check that product doesn't exceed MAX_SIZE.
