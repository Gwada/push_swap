/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:20:52 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/31 21:20:57 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	find_first_insert(t_roll *r, int *fst, int *lst, int i)
{
	*fst = -1;
	while (++i < r->nb_a)
	{
		if (*fst == -1)
			if (value_insert(r, NULL, ATNBR, ALNBR))
				*fst = i;
		rotate(NULL, &r->a, 0, 0);
	}
	i = r->nb_a + 1;
	*lst = -1;
	while (--i > 0)
	{
		if (*lst == -1)
			if (value_insert(r, NULL, ATNBR, ALNBR))
				*lst = i;
		r_rotate(NULL, &r->a, 0, 0);
	}
}

void			clean_b(t_roll *r, int fst, int lst, int value)
{
	while (r->nb_b > 0)
	{
		find_first_insert(r, &fst, &lst, -1);
		r->b_rot = r->nb_a - (r->nb_a - fst) <= r->nb_a - lst ? fst : lst;
		value = r->b_rot;
		if (r->b_rot <= r->nb_a / 2)
			while (r->b_rot-- > 0)
				rotate(r, &r->a, 'a', GOOD);
		else
			while (r->b_rot++ < r->nb_a)
				r_rotate(r, &r->a, 'a', GOOD);
		value == fst ? b_push(r, ATNBR, ALNBR) : b_push(r, ATNBR, ALNBR);
	}
}

void			last_step(t_roll *r, int i)
{
	clean_b(r, r->nb_a, 0, 0);
	while (++i < r->nb_a)
	{
		ALNBR == r->a_min ? r->b_rot = i : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	if (r->b_rot <= r->nb_a / 2)
		while (r->b_rot-- > 0)
			rotate(r, &r->a, 'a', GOOD);
	else
		while (r->b_rot++ < r->nb_a)
			r_rotate(r, &r->a, 'a', GOOD);
}
