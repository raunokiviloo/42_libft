/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:44 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;	

	if (dst == src || dst == NULL || src == NULL)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < n)
			buf[i] = src[i++];
		return (dst);
	}
	i = n;
	while (i > 0)
	{
		dst[i - 1] = buf[i - 1];
		i--;
	}
	return (dst);
}
/*Using temp array prevents data loss when src and dst memory is overlapping.
Copy forward if dst < src, copy backwards if dst > src.*/
