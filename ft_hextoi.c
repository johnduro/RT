/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 12:14:55 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 12:14:59 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*convert_alpha_inhex(const char *str)
{
	char	*new;
	int		i;

	if (str[0] == '0' && str[1] == 'x')
		str += 2;
	new = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 70)
			new[i] = str[i] - 7;
		else if (str[i] >= 97 && str[i] <= 102)
			new[i] = str[i] - 39;
		else
			new[i] = str[i];
		i++;
	}
	return (new);
}

int				ft_hextoi(const char *str)
{
	char	*tmp;
	int		neg;
	int		i;
	int		nb;

	nb = 0;
	neg = 1;
	i = 0;
	while (*str && ft_isspace(*str) && *str != 43 && *str != 45)
		str++;
	tmp = convert_alpha_inhex(str);
	if (tmp[i] == '-')
	{
		i++;
		neg = -1;
	}
	else if (tmp[i] == '+')
		i++;
	while (tmp[i] && tmp[i] >= 48 && tmp[i] <= 64)
		nb = nb * 16 + tmp[i++] - '0';
	free(tmp);
	return (nb * neg);
}
