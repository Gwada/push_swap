/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:30:19 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/05 08:40:04 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	small_sort(t_roll *r, int i)
{
	while (++i < r->nb_a)
	{
		ALBD ^ GOOD ? ALBD = NO_CHECK : 0;
		rotate(NULL, &r->a, 0, 0);
	}
}

static	void	medium_sort(t_roll *r, t_tab *t, int n, int i)
{
	while (++i < r->nb_a)
	{
		if (ALBD ^ GOOD)
		{
			if (!n)
				ALBD = ALNBR <= (int)t[r->size / 2].n ? NO_CHECK : CHECK;
			else if (n == 1)
				ALBD = ALNBR <= (int)t[(r->size / 4) * 3].n ? NO_CHECK : CHECK;
			else
				ALBD = NO_CHECK;
		}
		rotate(NULL, &r->a, 0, 0);
	}
}

static	void	big_sort(t_roll *r, t_tab *t, int n, int i)
{
	while (++i < r->nb_a)
	{
		if (ALBD ^ GOOD)
		{
			if (!n)
				ALBD = ALNBR <= (int)t[r->size / 2].n ? NO_CHECK : CHECK;
			else if (n == 1)
				ALBD = ALNBR <= (int)t[r->size / 4 * 3].n ? NO_CHECK : CHECK;
			else if (n == 2)
				ALBD = ALNBR <= (int)t[r->size / 8 * 7].n ? NO_CHECK : CHECK;
			else
				ALBD = NO_CHECK;
		}
		rotate(NULL, &r->a, 0, 0);
	}
}

void			fixe_push(t_roll *r, t_tab *t, int i)
{
	if (r->size <= 20)
		small_sort(r, -1);
	else if (r->size <= 250)
		medium_sort(r, t, i, -1);
	else
		big_sort(r, t, i, -1);
}
