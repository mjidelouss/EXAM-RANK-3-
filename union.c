/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:58:41 by aelousse          #+#    #+#             */
/*   Updated: 2022/01/03 21:58:55 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	char	hash[256] = {0};

	char	*s1 = av[1], *s2 = av[2];
	while (*s1)
	{
		if (hash[(int)*s1] == 0)
		{
			putchar(*s1);
			hash[(int)*s1]++;
		}
		s1++;
	}
	while (*s2)
	{
		if (hash[(int)*s2] == 0)
		{
			putchar(*s2);
			hash[(int)*s2]++;
		}
		s2++;
	}
	putchar('\n');
}
