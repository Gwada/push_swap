/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:03:51 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/01 21:04:08 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			i_b_max_finder(t_roll *r, int *rot, int i)
{
	int			value;

	value = r->b_max;
	while (++i < r->nb_b)
	{
		BLNBR == r->b_max ? *rot = i : 0;
		rotate(NULL, &r->b, 0, 0);
	}
}

void			i_b_min_finder(t_roll *r, int *rot, int i)
{
	int			value;

	value = r->b_min;
	while (++i < r->nb_b)
	{
		BLNBR < ALNBR && BLNBR > value ? *rot = i : 0;
		BLNBR < ALNBR && BLNBR > value ? value = BLNBR : 0;
		rotate(NULL, &r->b, 0, 0);
	}
}

static	void	max_insert(t_roll *r, int rot, int i, int max)
{
	i_b_max_finder(r, &rot, i);
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b', GOOD);
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b', GOOD);
	while (r->nb_b > 0 && BLNBR > ATNBR && BLNBR > max)
	{
		simple_push(r, &r->b, &r->a, 'a');
		ALBD = GOOD;
	}
}

static	void	min_insert(t_roll *r, int rot, int i, int min)
{
	i_b_min_finder(r, &rot, i);
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b', GOOD);
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b', GOOD);
	while (r->nb_b > 0 && BLNBR < ALNBR)
	{
		simple_push(r, &r->b, &r->a, 'a');
		ALBD = GOOD;
	}
	(void)min;
}

void			hard_insert(t_roll *r, int rot, int min, int max)
{
	if (ALBD & GOOD)
	{
		r->b_min < ALNBR ? min_insert(r, rot, -1, min) : 0;
		r->b_max > ATNBR ? max_insert(r, rot, -1, max) : 0;
	}
	else if (ATBD & GOOD)
	{
		if (r->b_max > max)
		{
			max_insert(r, rot, -1, max);
			rotate(r, &r->a, 'a', GOOD);
		}
		r->b_min < min ? min_insert(r, rot, -1, min) : 0;
	}
}
