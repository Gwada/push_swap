/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:39:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/27 21:22:25 by dlavaury         ###   ########.fr       */
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

# define NO_CHECK	(1 << 1)
# define CHECK		(1 << 2)
# define SWAP		(1 << 3)
# define ROT		(1 << 4)
# define R_ROT		(1 << 5)
# define PUSH		(1 << 6)
# define S_PUSH		(1 << 7)

# define CHR		ft_strchr
# define ISNUM		"0123456789"
# define LNBR		low->nbr
# define TNBR		top->nbr
# define LBD		low->bd
# define TBD		top->bd
# define ALNBR		r->a.LNBR
# define BLNBR		r->b.LNBR
# define ATNBR		r->a.TNBR
# define BTNBR		r->b.TNBR
# define ALBD		r->a.LBD
# define BLBD		r->b.LBD
# define ATBD		r->a.TBD
# define BTBD		r->b.TBD
# define ALLNBR		r->a.low->LNBR
# define BLLNBR		r->b.low->LNBR
# define ALLBD		r->a.low->LBD
# define BLLBD		r->b.low->LBD
# define ATTBD		r->a.top->TBD
# define BTTBD		r->b.top->TBD
# define ATTNBR		r->a.top->TNBR
# define BTTNBR		r->b.top->TNBR
# define ALLLNBR	r->a.low->low->LNBR
# define ATTTNBR	r->a.top->top->TNBR
# define ALLLBD		r->a.low->low->LBD
# define ATTTBD		r->a.top->top->TBD

/*
** STRUCTURES
*/

typedef struct		s_pile
{
	char			bd;

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
	int				nb_a;
	int				min;
	int				max;
	int				nb_b;
	int				dep;
	int				pvt;
}					t_roll;

/*
** PROTOTYPES
*/

int					init_struct(t_roll *r, char **argv, int size);
void				init_tab(t_tab *t, t_roll *r, char **a, int i);

void				display_piles(t_roll *r, t_pile *a, t_pile *b);

void				find_best_rotation(t_roll *r, int rot, int state);
void				fixe_best_rotate(t_roll *r, int min, int max, int i);
void				find_best_rot(t_roll *r, t_tab *t, int b_rot, int i);

void				first_step(t_roll *r, t_tab *t, int i, int start);
void				check_limits(t_roll *r, int i, int min, int max);
void				fixe_push(t_roll *r, int i, int min, int max);
void				second_step(t_roll *r, int i);
void				nearest_rotation(t_roll *r, int checker, int fst, int lst);
int					nearest_checker(t_roll *r, int fst, int lst);
int					value_insert(t_roll *r, int *rot, int min, int max);
void				easy_insert(t_roll *r, int rot, int min, int max);
void				i_b_right_insert(t_roll *r, int *rot, int min, int max);
void				i_b_left_insert(t_roll *r, int *rot, int min, int max);
void				hard_insert(t_roll *r, int rot, int min, int max);
void				i_b_max_finder(t_roll *r, int *rot, int i);
void				i_b_min_finder(t_roll *r, int *rot, int i);
int					b_push(t_roll *r, int min, int max);
void				last_step(t_roll *r, int i);
void				clean_b(t_roll *r, int fst, int lst, int value);

void				push(t_roll *r, t_pile *src, t_pile *dst, char pile);
void				simple_push(t_roll *r, t_pile *src, t_pile *dst, char pile);
void				swap(t_roll *r, t_pile *p, char pile);
int					a_insert(t_roll *r, int rot_a, int value, int rot);
void				rotate(t_roll *r, t_pile *p, char pile);
void				r_rotate(t_roll *r, t_pile *p, char pile);
void				d_rotate(t_roll *r, int state);
int					calibrate_rot(t_roll *r, int rot, int i);

void				ft_qsort(int *t, int size, int i, int j);
void				ft_ps_qsort(t_tab *t, int size, int i, int j);
void				pile_sort(t_roll *r, int *t, int size, int i);

void				push_swap(t_roll *r, char **p, int size);

#endif
