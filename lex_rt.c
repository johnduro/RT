/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:27:13 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 19:33:04 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "rt.h"
#include "get_next_line.h"

static t_lx			*init_lex(void)
{
	t_lx	*new;

	if ((new = (t_lx *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

static t_lex		*init_node(char *str)
{
	t_lex	*new;

	if ((new = (t_lex *)malloc(sizeof(*new))) == NULL)
		ft_exit("malloc", 1);
	new->str = ft_strtrim(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void			add_to_list(t_lx *lex, char *buf)
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

t_lx				*get_lex(char *scene)
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
