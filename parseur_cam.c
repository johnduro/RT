/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:41:53 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 19:42:36 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include "libft.h"

void		add_cam(t_env *e, t_lex *lex)
{
	t_cam	*new;
	t_lex	*tmp;
	char	**tab;

	if ((new = (t_cam *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
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
	e->cam = new;
}
