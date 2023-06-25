/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:54:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/06/25 11:54:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "wordle.h"

void	print_underscore(int nb);
void	print_input(char **last_input, char **color_input, int input_nb);

int	print_game(char *word)
{
	int	i = 6;
	char **last_input;
	char **color_input;

	last_input = malloc(sizeof(char *) * 6);
	color_input = malloc(sizeof(char *) * 6);
	initialize_str(last_input);
	initialize_str(color_input);
	while (i > 0)
	{
		if (last_input[0])
			print_input(last_input, color_input, i);
		print_underscore(i);
		last_input[6 - i] = input(word);
		color_input[6 - i] = verify_letters(last_input[6 - i], word);
		if (strncmp(color_input[6 - i], "ggggg", 5) == 0)
		{
			print_input(last_input, color_input, i - 1);
			print_underscore(i - 1);
			if (i != 6)
				printf("\nWell done ! You find the word in %d tries !\n\n", 7 - i);
			else
				printf("\nWell done ! You find the word in %d try !\n\n", 7 - i);
			free_all(last_input, color_input, i);
			free(word);
			exit(0);
		}
		i--;
	}
	print_input(last_input, color_input, i);
	printf("Too bad, you failed ! The word was : %s\n\n", word);
	free_all(last_input, color_input, i);
	free(word);
	return (0);
}

void	print_input(char **last_input, char **color, int input_nb)
{
	int	j;
	int i = 0;

	printf("\n\n");
	while (i < 6 - input_nb)
	{
		printf("		");
		j = 0;
		while (last_input[i][j])
		{
			if (color[i][j] == 'g')
				printf(GREEN);
			else if (color[i][j] == 'y')
				printf(YELLOW);
			printf("%c ", last_input[i][j]);
			printf(RESET);
			j++;
		}
		printf("\n\n\n");
		i++;
	}
}

void	print_underscore(int nb)
{
	int i = 0;

	while (++i <= nb)
		printf("		_ _ _ _ _\n\n\n");
}