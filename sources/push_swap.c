/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/06 16:23:56 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		error_checker(t_roll *r)
{
	int			i;
	int			total;

	i = -1;
	total = 0;
	while (++i < r->nb_a)
	{
		ALBD & NO_CHECK ? ++total : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	return (total);
}

static	void	fixe_push(t_roll *r, int i)
{
	while (++i < r->nb_a)
	{
		ALBD ^ GOOD ? ALBD = NO_CHECK : 0;
		rotate(NULL, &r->a, 0, 0);
	}
}

void			push_swap(t_roll *r, char **p, unsigned int size)
{
	t_tab		t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	r->bd &= ~COLOR;
	r->bd &= ~VISUAL;
	r->bd |= GOOD;
	find_best_rot(r, t, 0, -1);
	first_step(r, t, -1, 0);
	fixe_push(r, -1);
	while (error_checker(r))
		nearest_rotation(r, r->nb_a, 0);
	last_step(r, -1);
}
