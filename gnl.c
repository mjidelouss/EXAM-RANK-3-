/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:59:02 by aelousse          #+#    #+#             */
/*   Updated: 2022/01/03 21:59:38 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *ft_strdup(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    char *t = malloc(i + 1);
    if (!t)
        return (0);
    i = -1;
    while (s[++i])
        t[i] = s[i];
    t[i] = 0;
    return (t);
}

char *get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    char buff[1];
    char line[8000000] = {0};
    int i = 0;
    int n;
    while ((n = read(fd, buff, 1)) > 0)
    {
        line[i++] = buff[0];
        if (buff[0] == '\n')
            return (ft_strdup(line));
    }
    return (!line[0] ? NULL : ft_strdup(line));
}
