/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:52:11 by mle-roy           #+#    #+#             */
/*   Updated: 2014/01/27 17:12:39 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && *s1 && *s2)
	{
		if (*s1++ != *s2++)
			return ((unsigned char) *(s1 - 1) - (unsigned char) *(s2 - 1));
		if (n == 0)
			return (0);
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
