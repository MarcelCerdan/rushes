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

int	check_double(char *input, int i)
{
	int j = i - 1;

	while (j > 0)
	{
		if (input[j] == input[i])
			return (1);
		j--;
	}
	return (0);
}