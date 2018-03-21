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

void		fixe_push(t_roll *r, int i, int min, int max)
{
	int		j;
	int		b_fst;
	int		b_lst;
	int		value;

	while (++i < r->nb_a && (b_fst = -1) && (b_lst = -1))
	{
		if (ALBD & PUSH && (j = -1) && !(min = 0) && !(max = 0))
		{
			value = ALNBR;
			while (++j < r->nb_a)
			{
				if (ALBD & GOOD && ((min = ALNBR) || !(min = ALNBR)))
				{
					while (ALLBD ^ GOOD)
						rotate(NULL, &r->a, 0);
					max = ALLNBR;
					while (ALBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
					if (b_fst == -1 && ((min < max && value > min && value < max)
					|| (min > max && (value > min || value < max))))
						b_fst = r->nb_a - (r->nb_a - j);
				}
				rotate(NULL, &r->a, 0);
			}
			while (j-- > 0)
			{
				if (ALBD & GOOD && ((max = ALNBR) || !(max = ALNBR)))
				{
					while (ATBD ^ GOOD)
							r_rotate(NULL, &r->a, 0);
					min = ATNBR;
					while (ALBD ^ GOOD)
						rotate(NULL, &r->a, 0);
					if (b_lst == -1 && ((min < max && value > min && value < max)
					|| (min > max && (value > min || value < max))))
						b_lst = r->nb_a - (j + 1);
				}
				r_rotate(NULL, &r->a, 0);
			}
			ALBD = b_fst <= b_lst ? CHECK : NO_CHECK;
		}
		rotate(NULL, &r->a, 0);
	}
}

void		clean_b(t_roll *r)
{
	ft_printf ("{green}{bold}{underline}IN CLEAN{eoc}\n");
	int		i;
	int		fst;
	int		lst;
	int		l_min;
	int		l_max;
	int		t_min;
	int		t_max;
	int		value;

	display_piles(r, &r->a, &r->b);
	while (r->nb_b)
	{
		fst = r->nb_a;
		lst = 0;
		i = -1;
		while (++i < r->nb_a)
		{
			if (ATBD & GOOD && fst == r->nb_a)
			{
				l_min = ATNBR;
				while (ALBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				l_max = ALNBR;
				while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
				value_insert(r, NULL, l_min, l_max) ? fst = i : 0;
			}
			rotate(NULL, &r->a, 0);
		}
		while (i-- > 0)
		{
			if (ALBD & GOOD && !lst)
			{
				t_max = ALNBR;
				while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
				t_min = ATNBR;
				while (ALBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				value_insert(r, NULL, t_min, t_max) ? lst = i + 1 : 0;
			}
			r_rotate(NULL, &r->a, 0);
		}
		r->b_rot = r->nb_a - (r->nb_a - fst) <= r->nb_a - lst ? fst : lst;
		value = r->b_rot;
		if (r->b_rot <= r->nb_a / 2)
			while (r->b_rot-- > 0)
				rotate(r, &r->a, 'a');
		else
			while (r->b_rot++ < r->nb_a)
				r_rotate(r, &r->a, 'a');
		value == fst ? b_push(r, l_min, l_max) : b_push(r, t_min, t_max);
		if (!r->nb_b)
			return ;
	}
	ft_printf ("{green}{bold}{underline}END CLEAN{eoc}\n");
}
