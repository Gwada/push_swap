/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:16:09 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/25 18:32:03 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_roll *r, t_pile *p, char pile)
{
	t_pile	*tmp;

	if (!p->low || p->low->root)
		return ;

	p->LBD = GOOD;
	p->low->LBD = GOOD;
	tmp = p->low;
	p->low->low->top = &r->a;
	p->low = p->low->low;
	tmp->low = p->low->low;
	tmp->top = p->low;
	tmp->top->low = tmp;
	tmp->low->top = tmp;
	r ? ++r->dep : 0;
	if (!r || !pile)
		return ;
	if (r->bd & COLOR)
		ft_printf("{magenta}{bold}s%c{eoc}\n", pile);
	else
		ft_printf("s%c\n", pile);
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}

static	int	b_rot(t_roll *r, int value)
{
	int		i;
	int		rot_b;

	i = -1;
	rot_b = -1;
	while (++i < r->nb_b)
	{
		if (rot_b == -1 && ((value > BTNBR && value < BLNBR)
		|| (BTNBR > BLNBR && (value > BTNBR || value < BLNBR))))
			rot_b = i > (r->nb_b / 2) ? r->nb_b - i : i;
		rotate(NULL, &r->b, 0);
	}
	return (rot_b);
}

static	int	a_rot(t_roll *r, int *min, int *max, int *rot_a)
{
	int		i;
	int		rot;
	int		value;

	i = -1;
	rot = -1;
	value = ALNBR;
	while (++i < r->nb_a)
	{
		if (ATBD & GOOD && rot == -1)
		{
			*min = ATNBR;
			*rot_a = r->nb_a - i;
			while (ALBD ^ GOOD && --*rot_a != r->nb_a + 1)
				rotate(NULL, &r->a, 0);
			*max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			if ((*min > *max && (value > *min || value < *max))
			|| (value > *min && value < *max))
				rot = i <= r->nb_a / 2 ? i - 1 : i;
		}
		rotate(NULL, &r->a, 0);
	}
	return (rot);
}

int			a_insert(t_roll *r, int rot_a, int value, int rot)
{
	int		min;
	int		max;
	int		n_dep_l;
	int		n_dep_t;
	int		b_rot_a;

	rot = a_rot(r, &min, &max, &rot_a);
	n_dep_l = rot > (r->nb_a / 2) ? r->nb_a - rot : rot;
	n_dep_t = rot_a > (r->nb_a / 2) ? r->nb_a - rot_a : rot_a;
	b_rot_a = n_dep_t < n_dep_l ? n_dep_t : n_dep_l;
	if (b_rot_a > 1 && b_rot_a * 2 + 2 <= b_rot(r, value) + 1)
	{
		rot = n_dep_t < n_dep_l ? rot_a : rot;
		simple_push(r, &r->a, &r->b, 'b');
		if (rot <= r->nb_a / 2)
			while (ATNBR != min)
				rotate(r, &r->a, 'a');
		else
			while (ALNBR != max)
				r_rotate(r, &r->a, 'a');
		BLBD = GOOD;
		simple_push(r, &r->b, &r->a, 'a');
		return (0);
	}
	return (1);
}
