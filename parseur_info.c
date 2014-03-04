/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:34:36 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 19:35:20 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void		add_info(t_env *e, t_lex *lex)
{
	t_lex	*tmp;
	char	**tab;

	tmp = lex->next;
	while (tmp && (tmp->str)[0] != '#')
	{
		tab = ft_strsplitspace(tmp->str);
		if (!ft_strcmp(tab[0], "width"))
			e->width = ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "height"))
			e->height = ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "focal"))
			e->focal = ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "color"))
			e->color = ft_hextoi(tab[1]);
		ft_tabfree(&tab);
		tmp = tmp->next;
	}
}
