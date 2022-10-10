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

	if (nelem == 0 || elsize == 0)
		return (NULL);
	arr = malloc(nelem * elsize);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nelem);
	return (arr);
}
//Need to initialize to 0.
