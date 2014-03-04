/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:38:09 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 19:39:20 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

static char		get_type(char *str)
{
	if (!ft_strcmp(str, "sphere"))
		return (SPH);
	else if (!ft_strcmp(str, "cylindre"))
		return (CYL);
	else if (!ft_strcmp(str, "plan"))
		return (PLAN);
	return (0);
}

static void		fill_obj(t_obj *new, t_lex *lex)
{
	char	**tab;

	while (lex && (lex->str)[0] != '#')
	{
		tab = ft_strsplitspace(lex->str);
		if (!ft_strcmp(tab[0], "type"))
			new->type = get_type(tab[1]);
		else if (!ft_strcmp(tab[0], "x"))
			new->x = (double) ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "y"))
			new->y = (double) ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "z"))
			new->z = (double) ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "size"))
			new->size = (double) ft_atoi(tab[1]);
		else if (!ft_strcmp(tab[0], "color"))
			new->color = ft_hextoi(tab[1]);
		ft_tabfree(&tab);
		lex = lex->next;
	}
}

static void		add_obj_env(t_env *e, t_obj *obj)
{
	t_obj	*tmp;

	if (e->obj == NULL)
		e->obj = obj;
	else
	{
		tmp = e->obj;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
		obj->prev = tmp;
	}
}

void			add_obj(t_env *e, t_lex *lex)
{
	t_obj	*new;
	char	**tab;

	if ((new = (t_obj *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
	new->next = NULL;
	new->prev = NULL;
	tab = ft_strsplitspace(lex->str);
	new->name = ft_strdup(tab[1]);
	ft_tabfree(&tab);
	fill_obj(new, lex->next);
	add_obj_env(e, new);
}
