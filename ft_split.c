/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:44 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static unsigned int	getwordcount(char const *str, char delimiter)
{
	unsigned int	count;

	count = 0;
	while (*str == delimiter)
		str++;
	if (*str)
		++count;
	while (*str)
	{
		if (*str == delimiter && *(str + 1) != delimiter
			&& *(str + 1) != '\0')
			++count;
		++str;
	}
	return (count);
}

void	freeall(char **target, int arr_index)
{
	while (arr_index >= 0)
		free(target[arr_index--]);
}

static int	alloc_toks(char const *str, char delimiter, char **target,
		unsigned int wordcount)
{
	int				arr_index;
	unsigned int	lettercount;

	arr_index = 0;
	lettercount = 0;
	while (*str && wordcount-- > 0)
	{
		while (*str == delimiter)
			str++;
		while (*str != delimiter && *str++ != '\0')
			lettercount++;
		if (lettercount)
			target[arr_index] = malloc(sizeof(**target) * (lettercount + 1));
		if (!target[arr_index])
		{
			freeall(target, arr_index);
			return (0);
		}
		lettercount = 0;
		arr_index++;
	}
	return (1);
}

void	write_toks(char const *str, char delimiter,
		char **target, unsigned int wordcount)
{
	int				arr_index;
	unsigned int	char_index;

	arr_index = 0;
	while (*str && wordcount-- > 0)
	{
		char_index = 0;
		while (*str == delimiter)
			str++;
		while (*str != delimiter && *str != '\0')
		{
			target[arr_index][char_index] = *str;
			char_index++;
			str++;
		}
		target[arr_index][char_index] = '\0';
		arr_index++;
	}
	target[arr_index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char			**tokens;
	unsigned int	wordcount;

	wordcount = getwordcount(s, c);
	if (!s || !wordcount)
		return (NULL);
	tokens = malloc(sizeof(*tokens) * (wordcount + 1));
	if (!tokens)
		return (NULL);
	if (!alloc_toks(s, c, tokens, wordcount))
	{
		free(tokens);
		return (NULL);
	}
	write_toks(s, c, tokens, wordcount);
	return (tokens);
}

// If we have an array of strings **arr ->
// sizeof(**arr) == 1 byte -> Size of a char
// sizeof(*arr) == -> 4 / 8 bytes depending on environment. -> Size of a ptr. 
/*int	main(void)
{
	char **output;
	char *test1 = "TEST";
	char delimiter = 'x';
	printf("String: %s\n", test1);
	printf("Delimiter: %c\n", delimiter);
	printf("Substrings: ");
	output = ft_split(test1, delimiter);
	while (output != NULL && *output != NULL)
		printf("%s, ", *output++);
	printf("\n-----------------------\n");
	
		test1 = "xxxxxxxxxxxTESTxTESTxxTESTx42xBBQxxxxxxx";
	delimiter = 'x';
	printf("String: %s\n", test1);
	printf("Delimiter: %c\n", delimiter);
	printf("Substrings: ");
	output = ft_split(test1, delimiter);
	while (output != NULL && *output != NULL)
		printf("%s, ", *output++);
	printf("\n-----------------------\n");
	
			test1 = "          43   1";
	delimiter = ' ';
	printf("String: %s\n", test1);
	printf("Delimiter: %c\n", delimiter);
	printf("Substrings: ");
	output = ft_split(test1, delimiter);
	while (output != NULL && *output != NULL)
		printf("%s, ", *output++);
	printf("\n-----------------------\n");
	
	test1 = "ThereIsNoDelimiter";
	delimiter = ' ';
	printf("String: %s\n", test1);
	printf("Delimiter: %c\n", delimiter);
	printf("Substrings: ");
	output = ft_split(test1, delimiter);
	while (output != NULL && *output != NULL)
		printf("%s, ", *output++);
	printf("\n-----------------------\n");
	
	test1 = "xxxxxxxxxxxxxxx";
	delimiter = 'x';
	printf("String: %s\n", test1);
	printf("Delimiter: %c\n", delimiter);
	printf("Substrings: ");
	output = ft_split(test1, delimiter);
	while (output != NULL && *output != NULL)
		printf("%s, ", *output++);
	printf("\n-----------------------\n");
	
	test1 = "";
	delimiter = 'y';
	printf("String: %s\n", test1);
	printf("Delimiter: %c\n", delimiter);
	printf("Substrings: ");
	output = ft_split(test1, delimiter);
	while (output != NULL && *output != NULL)
		printf("%s, ", *output++);
	printf("\n-----------------------\n");
}*/
