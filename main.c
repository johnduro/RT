/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:09:44 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 19:45:26 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "rt.h"
#include "libft.h"

void		get_pixel_color(t_env *e, int x, int y)
{
	t_obj			*obj;

	obj = e->obj;
	while (obj)
	{
		e->calc->dir->x = e->focal - e->cam->x;
		e->calc->dir->y = (-(e->width / 2) + x);
		e->calc->dir->z = ((e->height / 2) - y);
/*		if (check_inter_plan(e) == 1)
			calculate_color_plan(e, obj);
		if (check_inter_sphere(e, obj) == 1)
			calculate_color_sphere(e, obj);
		if (check_inter_cylindre(e, obj) == 1)
			calculate_color_cylindre(e, obj);
		if (e->calc->delta == e->focal)
			e->obj->color = e->color;*/
		/*
		** This uses to trace axes
		*/
		if (x == e->width / 2 || y == e->height / 2)
			e->color = 0x00FF00;
		obj = obj->next;
	}
}

int			expose_hook(t_env *e)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < e->height)
	{
		while (x < e->width)
		{
			e->calc->delta = e->focal;
			get_pixel_color(e, x, y);
			mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			x += 1;
		}
		x = 0;
		y +=1;
	}
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (e)
		return (0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env		*e;
	t_lx		*lex;

	if (argc != 2)
	{
		write(1, "./rt scene.sc\n", 14);
		return (0);
	}
	lex = get_lex(argv[1]);
	print_lex(lex); //nonon
	e = init_env(lex);
	printf("\n\n"); //nononon
	print_env(e); //nononon
	printf("coucou1\n");
	e->mlx = mlx_init();
	printf("coucou2\n");
	e->win = mlx_new_window(e->mlx, e->width, e->height, "RT");
	printf("coucou3\n");
	mlx_key_hook(e->win, key_hook, e);
	printf("coucou4\n");
//	mlx_expose_hook(e->win, expose_hook, e);
	printf("coucou5\n");
	mlx_loop(e->mlx);
	return (0);
}
