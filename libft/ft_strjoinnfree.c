/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:39:04 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 15:26:19 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinnfree(char *s1, char const *s2)
{
	char	*new;

	new = ft_strjoin((const char *) s1, s2);
	free(s1);
	return (new);
}
