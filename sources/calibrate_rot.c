/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibrate_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:59:12 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/01 20:59:30 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		calibrate(t_roll *r, int rot_a, int rot_b)
{
	if (!rot_b)
		return (0);
	if (rot_a <= r->nb_a / 2)
	{
		if (rot_b <= r->nb_b / 2)
			return (1);
		else if (rot_a + (r->nb_b - rot_b) >= rot_b)
			return (1);
	}
	else
	{
		if (rot_b > r->nb_b / 2)
			return (1);
		else if (r->nb_b - ((r->nb_a - rot_a) + rot_b) <= rot_b)
			return (1);
	}
	return (0);
}

static	int		p_calibrate(t_roll *r, int rot, int i)
{
	int			rot_b;

	rot_b = 0;
	while (++i < r->nb_b)
	{
		if ((ALNBR < BTNBR && ALNBR > BLNBR)
		|| (BTNBR < BLNBR && (ALNBR < BTNBR || ALNBR > BLNBR)))
			rot_b = i;
		rotate(NULL, &r->b, 0, 0);
	}
	return (calibrate(r, rot, rot_b));
}

int				calibrate_rot(t_roll *r, int rot, int i)
{
	int			ret;

	ret = 0;
	i = -1;
	while (++i < r->nb_a)
	{
		if (i == rot)
			ret = p_calibrate(r, rot, -1);
		rotate(NULL, &r->a, 0, 0);
	}
	return (ret);
}
