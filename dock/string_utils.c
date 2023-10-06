/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohadmin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:07:52 by ohadmin           #+#    #+#             */
/*   Updated: 2023/10/05 19:25:19 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n < 1)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL || fd < 0)
		return ;
	if (*str)
	{
		write(fd, str, 1);
		ft_putstr_fd(str + 1, fd);
	}
}
