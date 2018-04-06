/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_dif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:43:57 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/06 14:26:08 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		find_b_dep(t_roll *r, int rot_a, int ret, int i)
{
	while (++i < r->nb_b)
	{
		if ((ALNBR < BTNBR && ALNBR > BLNBR)
		|| (BTNBR < BLNBR && (ALNBR < BTNBR || ALNBR > BLNBR)))
			ret = i;
		rotate(NULL, &r->b, 0, 0);
	}
	if (ret > 0 && rot_a <= r->nb_a / 2)
	{
		if (ret <= r->nb_b / 2)
			ret = rot_a >= ret ? 0 : ret - rot_a;
		else
			ret = rot_a >= ret ? 0 : r->nb_b - ret;
	}
	else if (ret > 0 && ret > r->nb_b / 2)
	{
		if (r->nb_a - rot_a >= r->nb_b - ret)
			ret = 0;
		else
			ret = (r->nb_b - ret) - (r->nb_a - rot_a);
	}
	else if (ret > 0 && r->nb_a - rot_a >= r->nb_b - ret)
		ret = 0;
	return (ret);
}

static	void	next_dif(t_roll *r, int b_rot, int i)
{
	int			n_dep;
	int			b_dep;

	b_dep = r->size;
	while (++i < r->nb_a)
	{
		if (ALBD & NO_CHECK)
		{
			n_dep = 1;
			n_dep += (i <= r->nb_a / 2 ? i : r->nb_a - i);
			n_dep += find_b_dep(r, i, 0, -1);
			n_dep < b_dep ? b_rot = i : 0;
			n_dep < b_dep ? b_dep = n_dep : 0;
		}
		rotate(NULL, &r->a, 0, 0);
	}
	r->b_rot = b_rot;
}

void			nearest_rotation(t_roll *r, int fst, int lst)
{
	next_dif(r, r->size, -1);
	if (r->b_rot > 0)
	{
		ALBD |= r->b_rot-- <= r->nb_a / 2 ? ROT : R_ROT;
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
	if (ALBD & NO_CHECK && !nearest_checker(r, fst, lst))
		push(r, &r->a, &r->b, 'b');
}
