/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:13:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/06/25 12:13:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "wordle.h"

int	check_input(char *input, char *word);
int	verify_letters(char *input, char *word);

int	input(char *word)
{
	char *input;

	printf("Word : %s\n", word);
	printf(" What is the 5 letters word ? : ");
	scanf("%ms", &input);
	while (check_input(input, word) == 1)
	{
		printf(" What is the 5 letters word ? : ");
		scanf("%ms", &input);
	}
	return (0);
}

int	check_input(char *input, char *word)
{
	size_t	len = 0;
	char	*line;
	FILE 	*fp;

	errno = 0;
	fp = fopen(DICTIONARY, "r");
	string_toupper(input);
	string_toupper(word);
	if (!fp)
		perror("check_input");
	while (getline(&line, &len, fp) != -1)
	{
		string_toupper(line);
		if (strncmp(input, line, 5) == 0)
			return (verify_letters(input, word));
	}
	printf(" Not in word list !\n\n");
	return (1);
}

int	verify_letters(char *input, char *word)
{
	int	i = 0;
	int j = 0;

	printf("\n\n\n		");
	while (input[i])
	{
		j = 0;
		while (word[j])
		{
			if (input[i] == word[j])
			{
				if (i == j)
				{
					printf(GREEN);
					printf("%c ", input[i]);
					printf(RESET);
				}
				else if (check_double(input, i) == 0)
				{
					printf(YELLOW);
					printf("%c ", input[i]);
					printf(RESET);
				}
				else
					printf("%c ", input[i]);
				i++;
				j = 0;
			}
			j++;
		}
		printf("%c ", input[i]);
		i++;
	}
	printf("\n\n\n");
	return (0);
}