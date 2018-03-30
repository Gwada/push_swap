/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:30:19 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/30 18:08:20 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	small_sort(t_roll *r, t_tab *t, int n, int i)
{
	if (n > 1)
		return ;
	while (n < 2 && ++i < r->size)
	{
		if (ALBD ^ GOOD)
		{
			if (!n)
				ALBD = ALNBR <= (int)t[r->size / 2].n ? NO_CHECK : CHECK;
			else
				ALBD = NO_CHECK;
		}
		rotate(NULL, &r->a, 0);
	}
}

static	void	medium_sort(t_roll *r, t_tab *t, int n, int i)
{
//	ft_printf("{bold}{red}IN\tMEDIUM_SORT{eoc}\n");
	while (n < 4 && ++i < r->size)
	{
		if (ALBD ^ GOOD)
		{
			if (!n)
				ALBD = ALNBR <= (int)t[r->size / 4].n ? NO_CHECK : CHECK;
			else if (n == 1)
				ALBD = ALNBR <= (int)t[r->size / 2].n ? NO_CHECK : CHECK;
			else if (n == 2)
				ALBD = ALNBR <= (int)t[(r->size / 4) * 3].n ? NO_CHECK : CHECK;
			else
				ALBD = NO_CHECK;
		}
		rotate(NULL, &r->a, 0);
	}
//	ft_printf("{bold}{red}END\tMEDIUM_SORT{eoc}\n");
}

static	void	big_sort(t_roll *r, t_tab *t, int n, int i)
{
//	ft_printf("{bold}{red}IN\tBIG_SORT{eoc}\n");
	while (n < 6 && ++i < r->size)
	{
/*		if (ALBD ^ GOOD)
		{
			if (!n)
				ALBD = ALNBR <= (int)t[r->size / 4].n ? NO_CHECK : CHECK;
			else if (n == 1)
				ALBD = ALNBR <= (int)t[r->size / 2].n ? NO_CHECK : CHECK;
			else if (n == 2)
				ALBD = ALNBR <= (int)t[(r->size / 4) * 3].n ? NO_CHECK : CHECK;
			else
				ALBD = NO_CHECK;
		}*/

		if (ALBD ^ GOOD)
		{
			if (!n)
				ALBD = ALNBR <= (int)t[r->size / 6].n ? NO_CHECK : CHECK;
			else if (n == 1)
				ALBD = ALNBR <= (int)t[(r->size / 6) * 2].n ? NO_CHECK : CHECK;
			else if (n == 2)
				ALBD = ALNBR <= (int)t[r->size / 2].n ? NO_CHECK : CHECK;
			else if (n == 3)
				ALBD = ALNBR <= (int)t[(r->size / 6) * 4].n ? NO_CHECK : CHECK;
			else if (n == 4)
				ALBD = ALNBR <= (int)t[(r->size / 6) * 5].n ? NO_CHECK : CHECK;
			else
				ALBD = NO_CHECK;
		}
		rotate(NULL, &r->a, 0);
	}
//	ft_printf("{bold}{red}END\tBIG_SORT{eoc}\n");
}

void			fixe_push(t_roll *r, t_tab *t, int i)
{
	if (r->size <= 50)
		small_sort(r, t, i, -1);
	else if (r->size <= 200)
		medium_sort(r, t, i, -1);
	else
		big_sort(r, t, i, -1);
}
