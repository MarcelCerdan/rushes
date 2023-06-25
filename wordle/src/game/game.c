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

int	print_game(char *word)
{
	print_underscore(6);
	input(word);
	return (0);
}

void	print_underscore(int nb)
{
	int i = 0;

	while (++i <= nb)
		printf("		_ _ _ _ _\n\n\n");
}