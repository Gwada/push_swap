/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_best_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/27 21:18:21 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_limits(t_roll *r, int i, int min, int max)
{
	int		value;

	while (++i < r->size)
	{
		if (ALBD ^ GOOD)
		{
			value = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			min = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			max = ALNBR;
			while (ALNBR != value)
				r_rotate(NULL, &r->a, 0);
			if ((ALNBR > min && ALNBR < max)
			|| (min > max && (ALNBR > min || ALNBR < max)))
				ALBD = GOOD;
		}
		rotate(NULL, &r->a, 0);
	}
}

void		find_best_rot(t_roll *r, t_tab *t, int b_rot, int i)
{
	int		j;
	int		total;
	int		compare;

	compare = 0;
	while (++i < r->nb_a && (j = -1) && !(total = 0))
	{
		r->b_rot = i;
		first_step(r, t, -1, 0);
		while (++j < r->nb_a)
		{
			ALBD & GOOD ? ++total : 0;
			ALBD = 0;
			rotate(NULL, &r->a, 0);
		}
		total > compare ? b_rot = i : 0;
		total > compare ? compare = total : 0;
	}
	r->b_rot = b_rot;
}

static	void	fixe_fst(t_roll *r, int min, int max, int *b_fst)
{
	int			i;
	int			value;

	i = -1;
	value = ALNBR;
	while (++i < r->nb_a)
	{
		if (ALBD & GOOD)
		{
			min = ALNBR;
			while (ALLBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			max = ALLNBR;
			while (ALBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			if (*b_fst == -1 && ((value > min && value < max)
			|| (min > max && (value > min || value < max))))
				*b_fst = r->nb_a - (r->nb_a - i);
		}
		rotate(NULL, &r->a, 0);
	}
}

static	void	fixe_lst(t_roll *r, int min, int max, int *b_lst)
{
	int			i;
	int			value;

	i = r->nb_a;
	value = ALNBR;
	while (i-- > 0)
	{
		if (ALBD & GOOD)
		{
			max = ALNBR;
			while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
			min = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			if (*b_lst == -1 && ((value > min && value < max)
			|| (min > max && (value > min || value < max))))
				*b_lst = r->nb_a - (i + 1);
		}
		r_rotate(NULL, &r->a, 0);
	}
}

void			fixe_push(t_roll *r, int i, int min, int max)
{
	int			b_fst;
	int			b_lst;

	while (++i < r->nb_a)
	{
		if (ALBD & PUSH)
		{
			b_fst = -1;
			b_lst = -1;
			fixe_fst(r, min, max, &b_fst);
			fixe_lst(r, min, max, &b_lst);
			ALBD = b_fst <= b_lst ? CHECK : NO_CHECK;
		}
		rotate(NULL, &r->a, 0);
	}
}
