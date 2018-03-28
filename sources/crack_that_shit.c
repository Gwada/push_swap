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

void			fixe_push(t_roll *r, int i, int min, int max)
{
/*	min = r->a_max;
	max = ALNBR;
	while (++i < r->nb_a)
	{
		ALBD & GOOD && ALNBR < min ? r->b_rot = i : 0;
		ALBD & GOOD && ALNBR < min ? min = ALNBR : 0;
		if (ALBD ^ GOOD)
		//	ALBD = ALNBR <= r->pvt ? CHECK : NO_CHECK;
			ALBD = PUSH;
		rotate(NULL, &r->a, 0);
	}
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	min = 0;
	while (ATBD ^ GOOD && ++min)
		r_rotate(NULL, &r->a, 0);
	while (ALNBR != max)
		r_rotate(NULL, &r->a, 0);
	r->b_rot -= min / 2;
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
//	display_piles(r, &r->a, &r->b);
	i = -1;
	min = r->a_max;
	while (++i < r->size)
	{
		if (i <= r->size / 2)
			ALNBR <= r->pvt ? ALBD = NO_CHECK : 0;
//		if (i > r->nb_a / 2)
//			ALNBR <= r->pvt ? ALBD = CHECK : 0;
		rotate(NULL, &r->a, 0);
	}
//	display_piles(r, &r->a, &r->b);
//	ft_printf(".................................................\n");
	find_best_rotation(r, r->b_rot, 0);
//	display_piles(r, &r->a, &r->b);
//	ft_printf(".................................................\n");*/
/*	i = -1;
	int		j;
	while (42)
	{
		if (ALBD & PUSH)
		{
			--i;
			ALBD = ALNBR <= r->pvt ? CHECK : NO_CHECK;
			simple_push(r, &r->a, &r->b, 'b');
		}
		j = -1;
		min = -1;
		while (++j < r->nb_a)
		{
			ALBD & PUSH ? ++min : 0;
			rotate(NULL, &r->a, 0);
		}
		if (min == -1)
			break ;
		ALBD ^ PUSH ? rotate(r, &r->a, 'a') : 0;
	}
	min = r->a_max;
	while (++i < r->nb_a)
	{
		ALBD & GOOD && ALNBR < min ? r->b_rot = i : 0;
		ALBD & GOOD && ALNBR < min ? min = ALNBR : 0;
		rotate(NULL, &r->a, 0);
	}*/
/*	if (r->b_rot <= r->nb_a / 2)
		while (r->b_rot-- > 0)
			rotate(r, &r->a, 'a');
	else
		while (r->b_rot < r->nb_a)
			r_rotate(r, &r->a, 'a');
	while (ATBD ^ NO_CHECK)
		r_rotate(r, &r->a, 'a');
	while (r->nb_b > 0)
	{
		if (BLBD & NO_CHECK)
		{
			simple_push(r, &r->b, &r->a, 'a');
			rotate(r, &r->a, 'a');
		}
		else
			simple_push(r, &r->b, &r->a, 'a');
	}*/







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
