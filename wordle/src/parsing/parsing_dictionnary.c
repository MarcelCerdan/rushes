/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dictionnary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:46:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/06/24 17:46:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "wordle.h"

unsigned	check_dictionary();
char		*find_word(unsigned nb);

char	*random_word()
{
	unsigned	nb;
	unsigned	dictionary_size;
	char		*word;

	dictionary_size = check_dictionary();
	srand(time(NULL));
	nb = rand() % dictionary_size;
	printf("               __      __                   _      _            \n"
		   "               \\ \\    / / ___      _ _   __| |    | |     ___   \n"
		   "                \\ \\/\\/ / / _ \\    | '_| / _` |    | |    / -_)  \n"
		   "                 \\_/\\_/  \\___/   _|_|_  \\__,_|   _|_|_   \\___|  \n"
		   "               _|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| \n"
		   "               \"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' \n"
		   "");
	printf("\n\n Words available : %u\n\n", dictionary_size);
	if (nb == 0)
		nb++;
	word = find_word(nb);
	return (word);
}

unsigned	check_dictionary()
{
	FILE		*fp;
	size_t		len = 0;
	unsigned	line_nb;
	char		*line = NULL;

	errno = 0;
	fp = fopen(DICTIONARY, "r");
	if (fp == NULL)
		perror("check_dictionary");
	line_nb = 0;
	while (getline(&line, &len, fp) != -1)
	{
		line_nb++;
		if (strlen(line) < 5 || (strlen(line) > 5 && line[5] != '\n'))
		{
			printf("Error in line number %u of the dictionary.\n", line_nb);
			free(line);
			exit(0);
		}
	}
	fclose(fp);
	if (line_nb == 0)
	{
		printf("Dictionary is empty\n");
		free(line);
		exit(0);
	}
	return (free(line), line_nb);
}

char *find_word(unsigned nb)
{
	FILE		*fp;
	size_t		len = 0;
	char		*line = NULL;
	unsigned	line_nb;

	errno = 0;
	fp = fopen(DICTIONARY, "r");
	if (!fp)
		perror("find_word");
	line_nb = 0;
	while (line_nb < nb)
	{
		line_nb++;
		getline(&line, &len, fp);
	}
	fclose(fp);
	return (line);
}