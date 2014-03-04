/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:43:38 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 19:45:06 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"
#include <stdio.h> //nononononon

void		print_lex(t_lx *lex)
{
	t_lex	*browse;

	browse = lex->first;
	while (browse)
	{
		printf("LEX=%s\n", browse->str);
		browse = browse->next;
	}
}

void		print_env(t_env *e)
{
	t_obj	*obj;
	t_spot	*spot;

	printf("width=%d\n", e->width);
	printf("height=%d\n", e->height);
	printf("focal=%f\n", e->focal);
	printf("color=%d\n", e->color);
	if (e->cam)
		printf("CAM = x[%f]y[%f]z[%f]\n", e->cam->x, e->cam->y, e->cam->z);
	if (e->obj)
	{
		obj = e->obj;
		while (obj)
		{
			printf("OBJ\nname=%s\n", obj->name);
			printf("type=%d\n", obj->type);
			printf("color=%d\n", obj->color);
			printf("x[%f]y[%f]z[%f]\n", obj->x, obj->y, obj->z);
			printf("size=%f\n", obj->size);
			obj = obj->next;
		}
	}
	if (e->spot)
	{
		spot = e->spot;
		while (spot)
		{
			printf("SPOT\nname=%s\n", spot->name);
			printf("x[%f]y[%f]z[%f]\n", spot->x, spot->y, spot->z);
			spot = spot->next;
		}
	}
}
