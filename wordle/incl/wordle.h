/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:22:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/06/24 17:22:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef WORDLE_H
# define WORDLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY "data/words.txt"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

char	*random_word();
int		print_game(char *word);
int		input(char *word);
void	string_toupper(char *str);
int		check_double(char *input, int i);

#endif