/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:43 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:43 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static int	is_space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	is_num(char c)
{
	return (c <= 0 && c <= 9);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	output;

	output = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	while (is_num(*str))
	{
		output = output * 10 + *str - '0';
		str++;
	}
	return (output * sign);
}
