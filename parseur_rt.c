/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:31:11 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 19:33:33 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rt.h"
#include "libft.h"

static int			check_env(t_env *e)
{
	if (e->width <= 0 || e->height <= 0)
		return (1);
	else if (e->cam == NULL || e->obj == NULL || e->spot == NULL)
		return (1);
	return (0);
}

t_env				*init_env(t_lx *lex)
{
	t_env	*new;
	t_lex	*browse;

	if ((new = (t_env *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
	browse = lex->first;
	while (browse)
	{
		if (!ft_strncmp(browse->str, "#INFO", 5))
			add_info(new, browse);
		if (!ft_strncmp(browse->str, "#SPOT", 5))
			add_spot(new, browse);
		if (!ft_strncmp(browse->str, "#OBJ", 4))
			add_obj(new, browse);
		if (!ft_strncmp(browse->str, "#CAM", 4))
			add_cam(new, browse);
		browse = browse->next;
	}
	if (check_env(new))
	{
		write(2, "RT error: not enought information\n", 34);
		exit(0);
	}
//	new->mlx = mlx_init();
//	new->win = mlx_new_window(new->mlx, new->width, new->height, "RT");
	return (new);
}
