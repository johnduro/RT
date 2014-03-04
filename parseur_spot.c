/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_spot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:35:30 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 19:37:46 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include "libft.h"

static void		add_spot_env(t_env *e, t_spot *spot)
{
	t_spot	*tmp;

	if (e->spot == NULL)
		e->spot = spot;
	else
	{
		tmp = e->spot;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = spot;
		spot->prev = tmp;
	}
}

void			add_spot(t_env *e, t_lex *lex)
{
	t_spot		*new;
	char		**tab;
	t_lex		*tmp;

	if ((new = (t_spot *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
	new->next = NULL;
	new->prev = NULL;
	tab = ft_strsplitspace(lex->str);
	new->name = ft_strdup(tab[1]);
	ft_tabfree(&tab);
	tmp = lex->next;
	while (tmp && (tmp->str)[0] != '#')
	{
		tab = ft_strsplitspace(tmp->str);
		if (!ft_strcmp(tab[0], "x"))
			new->x = (double) ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "y"))
			new->y = (double) ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "z"))
			new->z = (double) ft_atoi(tab[1]);
		ft_tabfree(&tab);
		tmp = tmp->next;
	}
	add_spot_env(e, new);
}
