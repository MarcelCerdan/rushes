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

char	*input(char *word)
{
	char *input;

	printf("Word : %s\n", word);
	printf(" What is the word ? : ");
	scanf("%ms", &input);
	while (check_input(input, word) == 1)
	{
		printf(" What is the word ? : ");
		scanf("%ms", &input);
	}
	return (input);
}

int	check_input(char *input, char *word)
{
	size_t	len = 0;
	char	*line = NULL;
	FILE 	*fp;

	errno = 0;
	fp = fopen(DICTIONARY, "r");
	string_toupper(input);
	string_toupper(word);
	if (fp == NULL)
		perror("check_input");
	while (getline(&line, &len, fp) != -1)
	{
		string_toupper(line);
		if (strncmp(input, line, 5) == 0 && strlen(input) == 5)
			return (free(line), fclose(fp), 0);
	}
	free(line);
	fclose(fp);
	printf("\n Not in word list !\n\n");
	return (1);
}

char	*verify_letters(char *input, char *word)
{
	int 	j;
	int		i = 0;
	char	*color = malloc(sizeof(char) * 6);

	while (i < 5)
	{
		color[i] = 'b';
		j = 0;
		while (j < 5)
		{
			if (input[i] == word[j])
			{
				if (i == j)
				{
					color[i] = 'g';
					break ;
				}
				else if (check_double(input, i, j, word) == 0)
					color[i] = 'y';
			}
			j++;
		}
		i++;
	}
	color[i] = '\0';
	return (color);
}