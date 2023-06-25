/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:28:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/06/25 12:28:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "wordle.h"

void string_toupper(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

int	check_double(char *input, int i, int j, char *word)
{
	int k = 0;
	int l = i - 1;
	int occurence = 1;
	int word_occurence = 1;
	int right_place = 0;

	while (l >= 0)
	{
		if (input[l] == input[i])
			occurence++;
		l--;
	}
	while (k < 5)
	{
		if (word[k] == word[j] && k != j)
			word_occurence++;
		k++;
	}
	k = 0;
	if (occurence < word_occurence)
	{
		while (k < 5)
		{
			if (input[k] == input[i] && word[k] == input[k])
				right_place++;
			k++;
		}
		if (right_place == word_occurence)
			return (1);
		else
			return (0);
	}
	else if (occurence <= word_occurence)
		return (0);
	return (1);
}

void	initialize_str(char **tab)
{
	int	i = 0;
	while (i < 5)
	{
		tab[i] = NULL;
		i++;
	}
}

void free_all(char **input, char **color, int max)
{
	int i = 0;

	while (i < 7 - max)
	{
		free(input[i]);
		free(color[i]);
		i++;
	}
	free(input);
	free(color);
}