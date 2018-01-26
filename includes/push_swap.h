/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:39:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/26 17:22:27 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
**	LIBRARIES
*/

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

/*
**	BINARY MASK
*/

# define GOOD		(1 << 0)
# define MIN		(1 << 1)
# define MAX		(1 << 2)
# define STRING		(1 << 3)
# define MINUS		(1 << 4)
# define VISUAL		(1 << 5)
# define COLOR		(1 << 6)
# define ERR		(1 << 7)

# define ONLY_R		(1 << 1)
# define MORE		(1 << 2)
# define SWAP		(1 << 3)
# define ROT		(1 << 4)
# define R_ROT		(1 << 5)
# define PUSH		(1 << 6)

# define CHR		ft_strchr
# define ISNUM		"0123456789"

/*
** STRUCTURES
*/

typedef struct		s_pile
{
	char			bd;

	int				pos;
	int				nbr;

	struct s_pile	*root;
	struct s_pile	*top;
	struct s_pile	*low;
}					t_pile;

typedef struct		s_tab
{
	long long		n;

	t_pile			m;
}					t_tab;

typedef	struct		s_roll
{
	int				size;

	char			bd;

	t_pile			a;
	t_pile			b;

	int				cor;
	int				b_rot;
	int				a_max;
	int				a_min;
	int				b_max;
	int				b_min;

	unsigned		nb_a;
	unsigned		nb_b;
}					t_roll;

/*
** PROTOTYPES
*/

int					init_struct(t_roll *r, char **argv, int size);
void				init_tab(t_tab *t, t_roll *r, char **a, int i);
void				init_sort(t_tab *t, t_roll *r, int i);

void				display_piles(t_roll *r, t_pile *a, t_pile *b);
void				display_pile(t_roll *r, t_pile *p, char pile);

void				crack_that_shit(t_tab *t, t_roll *r);
void				find_best_sort(t_tab *t, t_roll *r, int size, int i);
void				find_best_rotation(t_roll *r, int rot);
void				find_best_combinaison(t_tab *t, t_roll *r, int i);

void				push(t_roll *r, t_pile *dst, t_pile *src);
void				swap(t_roll *r, t_pile *p, char pile);
void				d_swap(t_roll *r);
void				rotate(t_roll *r, t_tab *t, t_pile *p, char pile);
void				r_rotate(t_roll *r, t_tab *t, t_pile *p, char pile);
void				d_rotate(t_tab *t, t_roll *r);
void				d_r_rotate(t_tab *t, t_roll *r);

void				ft_qsort(t_tab *t, int size, int i, int j);

void				push_swap(t_roll *r, char **p, int size);

#endif
