/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:02:36 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/04 12:34:59 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define SPH 1
# define PLAN 2
# define CYL 3

/*
** mettre x et y (win) dans la fonction expose hook et l'envoyer dans get_color
*/

typedef struct		s_lex
{
	char				*str;
	struct s_lex		*next;
	struct s_lex		*prev;
}					t_lex;

typedef struct		s_lx
{
	t_lex				*first;
	t_lex				*last;
}					t_lx;

typedef struct		s_vek
{
	double				x;
	double				y;
	double				z;
}					t_vek;

typedef struct		s_obj
{
	char				*name;
	char				type;
	int					color;
	double				x;
	double				y;
	double				z;
	double				size;
	struct s_obj		*next;
	struct s_obj		*prev;
}					t_obj;

typedef struct		s_spot
{
	char				*name;
	double				x;
	double				y;
	double				z;
	t_vek				*vek;
	struct s_spot		*next;
	struct s_spot		*prev;
}					t_spot;

typedef struct		s_cam
{
	double				x;
	double				y;
	double				z;
}					t_cam;

typedef struct		s_calc
{
	t_vek				*vek;
	double				spotnorm;
	double				dirnorm;
	double				cos;
	double				delta;
	int					r;
	int					g;
	int					b;
}					t_calc;

typedef struct		s_env
{
	void				*mlx;
	void				*win;
	int					width;
	int					height;
	double				focal;
	int					color;
	t_cam				*cam;
	t_obj				*obj;
	t_spot				*spot;
}					t_env;

int			ft_hextoi(const char *str);

#endif /* !RT_H */
