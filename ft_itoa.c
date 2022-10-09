/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:43 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:43 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
/*
- We want to know how many digits there are to allocate memory. 
- Extract digits in reverse order and convert to ASCII equivalents. 
- Reverse string
- Need to errorhandle INT_MIN
*/
//Really elegant intlen imo. Works for negatives and handles 0. 
static int getintlen(int n)
{
	int len = !n;
	while(n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char *ft_itoa(int n)
{
		
}

int main(void)
{
	int value = -108888;
	printf("%i", getintlen(value));
}
