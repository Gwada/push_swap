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

static	void	fixe_push_v2(t_roll *r, int i, int min, int max)
{
	int			j;
	int			left;
	int			right;
	int			value;


	while (++i < r->size)
	{
		if (ALBD ^ GOOD && (j = -1) && (right = -1) && (left = -1))
		{
			value = ALNBR;
			while (++j < r->size)
			{
				if (ATBD & GOOD && right == -1)
				{
					min = ATNBR;
					while (ALBD ^ GOOD)
						rotate(NULL, &r->a, 0);
					if ((value > min && value < ALNBR)
					|| (min > ALNBR && (value > min || value < ALNBR)))
						right = j;
					while (ATBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
				}
				rotate(NULL, &r->a, 0);
			}
			j = -1;
			while (++j < r->size)
			{
				if (ALBD & GOOD && left == -1)
				{
					max = ALNBR;
					while (ATBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
					if ((value > ATNBR && value < max)
					|| (ATNBR > max && ((value > ATNBR) || (value < max))))
						left = j;
					while (ALBD ^ GOOD)
						rotate(NULL, &r->a, 0);
				}
				r_rotate(NULL, &r->a, 0);
			}
			right > r->size /2 ? right = r->size - right : 0;
			left > r->size / 2 ? left = r->size - left : 0;
			//if ((right < ((r->size * 15) / 100)) || (left < ((r->size * 15) / 100)))
			if (right <= r->size / 10 || left <= r->size / 10)
				ALBD = NO_CHECK;
			else
				ALBD = CHECK;
		}
		rotate(NULL, &r->a, 0);
	}
}

void			fixe_push(t_roll *r, int i, int min, int max)
{
	if (r->size > 150)
		return (fixe_push_v2(r, -1, 0, 0));
	while (++i < r->size)
	{
		if (ALBD ^ GOOD)
			ALBD = ALNBR <= r->pvt ? CHECK : NO_CHECK;
		rotate(NULL, &r->a, 0);
	}
	(void)min;
	(void)i;
	(void)max;
}
