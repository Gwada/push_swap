/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_dif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:43:57 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/31 22:21:09 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		find_b_dep(t_roll *r, int ret, int i)
{
	int			value;
	while (++i < r->nb_b)
	{
		if ((ALNBR < BTNBR && ALNBR > BLNBR)
		|| (BTNBR < BLNBR && (ALNBR < BTNBR || ALNBR > BLNBR)))
			ret = i;
		rotate(NULL, &r->b, 0, 0);
	}
	if (!ret)
	{
		int lst = 0;
		int fst = 0;
		int max;
		i = -1;
		value = ALNBR;
		while (++i < r->nb_a)
		{
			if (ATBD & GOOD)
			{
				max = ATBD;
				while (ALBD ^ GOOD)
					rotate(NULL, &r->a, 0, 0);
				if ((value > max && value > BLNBR)
				|| (max > ALNBR && (value > max || value > ALNBR)))
					fst = i;
				while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0, 0);
			}
			rotate(NULL, &r->a, 0, 0);
		}
		i = -1;
		while (++i < r->nb_a)
		{
			if (ALBD & GOOD)
			{
				max = ALBD;
				while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0, 0);
				if ((value < max && value > ATNBR)
				|| (max < ATNBR && (value < max || value > ATNBR)))
					lst = i;
				while (ATBD ^ GOOD)
					rotate(NULL, &r->a, 0, 0);
			}
			r_rotate(NULL, &r->a, 0, 0);
		}
		if (r->nb_a - (r->nb_a - fst) <= r->nb_a - lst)
			ret = fst;
		else
			ret = lst;
	}
	return (ret);
}

static	void	next_dif(t_roll *r, int checker/*, int fst, int lst*/)
{
	int			i;
	int			n_dep_fst;
	int			n_dep_lst;

	i = -1;
	while (++i < r->nb_a)
	{
		fst == r->nb_a && ALBD & checker ? fst = i : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	while (i-- > 0)
	{
		!lst && ALBD & checker ? lst = i + 1 : 0;
		r_rotate(NULL, &r->a, 0, 0);
	}
	n_dep_fst = r->nb_a - (r->nb_a - fst);
	n_dep_lst = r->nb_a - lst;
	r->best_dif_dep = n_dep_fst <= n_dep_lst ? n_dep_fst : n_dep_lst;
	r->b_rot = (r->nb_a - (r->nb_a - fst) <= r->nb_a - lst) ? fst : lst;
//	int			i;
	int			n_dep;
	int			b_dep;
	int			b_rot;

	i = -1;
	b_dep = r->size;
	b_rot = r->size;
	while (++i < r->nb_a)
	{
		if (ALBD & checker)
		{
			n_dep = (i <= r->nb_a / 2 ? i : r->nb_a - i) + find_b_dep(r, 0, -1);
			ft_printf ("ALNBR = %11d n_dep = %3d\n", ALNBR, n_dep);
		}
		n_dep < b_dep ? b_rot = i : 0;
		n_dep < b_dep ? b_dep = n_dep : 0;
		rotate(NULL, &r->a, 0, 0);
	}
//	r->b_rot = b_rot;
	ft_printf ("b_dep = %3d b_rot = %3d\n", b_dep, b_rot);
}

void			nearest_rotation(t_roll *r, int checker, int fst, int lst)
{
	next_dif(r, checker/*, r->nb_a, 0*/);
	ALBD |= r->b_rot < r->nb_a / 2 ? ROT : R_ROT;
	if (ALBD & ROT)
	{
		ALBD &= ~ROT;
		if (nearest_checker(r, fst, lst))
			return ;
		return (rotate(r, &r->a, 'a', GOOD));
	}
	if (ALBD & R_ROT)
	{
		ALBD &= ~R_ROT;
		if (nearest_checker(r, fst, lst))
			return ;
		return (r_rotate(r, &r->a, 'a', GOOD));
	}
}
