/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_crack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:41:49 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/06 14:34:22 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_best_rotation(t_roll *r, int rot, int state)
{
	if (rot > r->nb_a / 2)
		while (++rot <= r->nb_a)
		{
			rotate(NULL, &r->a, 0, 0);
			state & R_ROT ? r->a.low->bd |= R_ROT : 0;
		}
	else
		while (rot-- > 0)
		{
			r_rotate(NULL, &r->a, 0, 0);
			state & ROT ? r->a.low->bd |= ROT : 0;
		}
}

static	int	pre_fixe(t_roll *r)
{
	while (ATBD ^ GOOD)
	{
		--r->b_rot < 0 ? r->b_rot = r->nb_a - 1 : 0;
		r_rotate(NULL, &r->a, 0, 0);
	}
	return (ALNBR);
}

void		fixe_best_rotate(t_roll *r, int min, int max, int i)
{
	int		value;

	value = pre_fixe(r);
	while (++i < r->nb_a)
	{
		if (ALBD & GOOD && max >= min && (max = ALNBR))
		{
			while (ALNBR != value)
				r_rotate(NULL, &r->a, 0, 0);
			while (ALNBR != max)
			{
				ALNBR >= min && ALNBR <= max ? ALBD = GOOD : 0;
				ALNBR >= min && ALNBR <= max ? min = ALNBR : 0;
				rotate(NULL, &r->a, 0, 0);
			}
			value = ALNBR;
			min = ALNBR;
		}
		ALBD & GOOD && ALNBR < min ? ALBD = NO_CHECK : 0;
		rotate(NULL, &r->a, 0, 0);
	}
}
