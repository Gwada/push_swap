/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:20:52 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/05 06:54:22 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	synchro(t_roll *r, int *rot, int *rot_a)
{
	if (*rot_a > 0 && *rot > 0)
	{
		if (*rot <= r->nb_b / 2 && ((*rot_a <= r->nb_a / 2)
		|| (*rot_a > r->nb_a / 2 && *rot >= *rot_a)))
			while ((*rot)-- > 0 && (*rot_a)-- > 0)
				d_rotate(r, ROT);
		else if ((*rot_a > r->nb_a / 2 && *rot > r->nb_b / 2)
		|| (*rot_a <= r->nb_a / 2 && r->nb_b - *rot >= r->nb_a - *rot_a))
			while ((*rot)++ < r->nb_b && (*rot_a)++ < r->nb_a)
				d_rotate(r, R_ROT);
	}
	if (*rot <= r->nb_b / 2)
		while (BLNBR != r->b_max)
			rotate(r, &r->b, 'b', 0);
	else
		while (BLNBR != r->b_max)
			r_rotate(r, &r->b, 'b', 0);
	if (*rot_a <= r->nb_a / 2)
		while ((*rot_a)-- > 0)
			rotate(r, &r->a, 'a', 0);
	else
		while ((*rot_a)++ < r->nb_a)
			r_rotate(r, &r->a, 'a', 0);
}

static	void	min_insert(t_roll *r, int rot, int i, int j)
{
	int			rot_a;

	while (++i < r->nb_b)
	{
		BLNBR == r->b_max ? rot = i : 0;
		rotate(NULL, &r->b, 0, 0);
	}
	while (++j < r->nb_a)
	{
		ALNBR == r->a_min ? rot_a = j : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	synchro(r, &rot, &rot_a);
	while (r->nb_b > 0)
		simple_push(r, &r->b, &r->a, 'a');
}

static	void	middle_insert(t_roll *r, int rot, int i, int j)
{
	int			rot_a;

	while (++i < r->nb_a)
	{
		ATNBR < r->b_max && r->b_max < ALNBR ? rot_a = i : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	while (++j < r->nb_b)
	{
		BLNBR == r->b_max ? rot = j : 0;
		rotate(NULL, &r->b, 0, 0);
	}
	synchro(r, &rot, &rot_a);
	while (BLNBR > ATNBR && BLNBR < ALNBR)
		simple_push(r, &r->b, &r->a, 'a');
}

static	void	max_insert(t_roll *r, int rot, int i, int j)
{
	int			rot_a;

	while (++i < r->nb_b)
	{
		BLNBR == r->b_max ? rot = i : 0;
		rotate(NULL, &r->b, 0, 0);
	}
	while (++j < r->nb_a)
	{
		ATNBR == r->a_max ? rot_a = j : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	synchro(r, &rot, &rot_a);
	while (BLNBR > ATNBR)
		simple_push(r, &r->b, &r->a, 'a');
}

void			last_step(t_roll *r, int i)
{
	int			rot;

	if (r->nb_b > 0 && r->b_max > r->a_max)
		max_insert(r, 0, i, i);
	while (r->nb_b > 0 && r->b_max > r->a_min)
		middle_insert(r, 0, -1, -1);
	if (r->nb_b > 0 && r->b_max < r->a_min)
		min_insert(r, 0, -1, -1);
	i = -1;
	while (++i < r->nb_a)
	{
		ALNBR == r->a_min ? rot = i : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	while (ALNBR != r->a_min)
	{
		rot <= r->nb_a / 2 ? rotate(r, &r->a, 'a', 0) : 0;
		rot > r->nb_a / 2 ? r_rotate(r, &r->a, 'a', 0) : 0;
	}
}
