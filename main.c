/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:09:44 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/03 21:54:21 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "rt.h"
#include "libft.h"
#include "get_next_line.h"

#include <stdio.h> //nononoonon

t_lx		*init_lex(void)
{
	t_lx	*new;

	if ((new = (t_lx *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

t_lex		*init_node(char *str)
{
	t_lex	*new;

	if ((new = (t_lex *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
	new->str = ft_strtrim(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		add_to_list(t_lx *lex, char *buf)
{
	t_lex	*node;

	node = init_node(buf);
	if (lex->first == NULL)
	{
		lex->first = node;
		lex->last = node;
	}
	else
	{
		lex->last->next = node;
		node->prev = lex->last;
		lex->last = node;
	}
}

t_lx		*get_lex(char *scene)
{
	t_lx	*lex;
	char	*buf;
	int		fd;
	int		ret;

	if ((fd = open(scene, O_RDONLY)) == -1)
		ft_exit("scene", 2);
	lex = init_lex();
	while ((ret = get_next_line(fd, &buf)))
	{
		if (ret == -1)
			exit(0);
		if (buf[0] != '$' && buf[0] != '\0')
			add_to_list(lex, buf);
		free(buf);
	}
	close(fd);
	return (lex);
}

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
			e->color = ;//a rajouter, atoihexa
		ft_tabfree(&tab);
		tmp = tmp->next;
	}
}

void		add_spot_env(t_env *e, t_spot *spot)
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

void		add_spot(t_env *e, t_lex *lex)
{
	t_spot		*new;
	char		**tab;
	t_lex		*tmp;

	if ((new = (t_spot *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
	new->next = NULL;
	new->prev = NULL;
	tab = ft_strsplitspace(lex->str);
	new = ft_strdup(tab[1]);
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

char		get_type(char *str)
{
	if (!ft_strcmp(str, "sphere"))
		return (SPH);
	else if (!ft_strcmp(str, "cylindre"))
		return (CYL);
	else if (!ft_strcmp(str, "plan"))
		return (PLAN);
}

void		fill_obj(t_obj *new, t_lex *lex)
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
			new->color = ;//faire le atoihexa
		ft_tabfree(&tab);
		lex = lex->next;
	}
}

void		add_obj_env(t_env *e, t_obj *obj)
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

void		add_obj(t_env *e, t_lex *lex)
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

t_env		*init_env(t_lx *lex)
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
		browse = browse->next;
	}
	if (check_env(new))
		exit(0);
	return (new);
}


int			main(int argc, char **argv)
{
//	t_env		*e;
	t_lx		*lex;

	if (argc != 2)
	{
		write(1, "./rt scene.sc\n", 14);
		return (0);
	}
	lex = get_lex(argv[1]);
	print_lex(lex);
	e = init_env(lex);
	return (0);
}
