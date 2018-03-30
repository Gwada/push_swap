/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:32:24 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/29 23:49:51 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	find_max(t_roll *r)
{
	int			i;

	i = 0;
	r->a_max = !r->nb_a ? 0 : ALNBR;
	r->a_min = !r->nb_a ? 0 : ALNBR;
	while (++i <= r->nb_a)
	{
		rotate(NULL, &r->a, 0);
		ALNBR > r->a_max ? r->a_max = ALNBR : 0;
		ALNBR < r->a_min ? r->a_min = ALNBR : 0;
	}
	i = 0;
	r->b_max = !r->nb_b ? 0 : BLNBR;
	r->b_min = !r->nb_b ? 0 : BLNBR;
	while (++i <= r->nb_b)
	{
		rotate(NULL, &r->b, 0);
		BLNBR > r->b_max ? r->b_max = BLNBR : 0;
		BLNBR < r->b_min ? r->b_min = BLNBR : 0;
	}
}

static	void	find_best_insert(t_roll *r, int rot, int i)
{
	int			max;
	int			min;

	max = r->b_max;
	min = r->b_min;
	if (r->nb_b > 1)
	{
		while (++i < r->nb_b)
		{
			if (((ALNBR < min || ALNBR > max) && BLNBR == max)
			|| (ALNBR < BTNBR && ALNBR > BLNBR))
				rot = i;
			rotate(NULL, &r->b, 0);
		}
		if (rot > r->nb_b / 2)
			while (rot++ < r->nb_b)
				r_rotate(r, &r->b, 'b');
		else
			while (rot-- > 0)
				rotate(r, &r->b, 'b');
	}
}

void			simple_push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
	t_pile		*tmp;

	tmp = src->low;
	src->low = src->low->low;
	tmp->low->top = src;
	tmp->top = dst;
	tmp->low = dst->low ? dst->low : dst;
	dst->low ? (dst->low->top = tmp) : (dst->top = tmp);
	!dst->top ? (dst->top = tmp) : (dst->low = tmp);
	r->nb_a += (pile == 'a') ? 1 : -1;
	r->nb_b += (pile == 'b') ? 1 : -1;
	find_max(r);
	r->bd & COLOR ? ft_printf("{red}{bold}p%c\n{eoc}", pile) : 0;
	!(r->bd & COLOR) ? ft_printf("p%c\n", pile) : 0;
	++r->dep;
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}

void			push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
	int			size;

	size = (pile == 'a' ? r->nb_b : r->nb_a);
	if (!(src->low) || src->low->root || !size)
		return ;
	size = (pile == 'a' ? r->nb_a : r->nb_b);
	if (!size || size == 1)
	{
		src->low->bd = GOOD;
		return (simple_push(r, src, dst, pile));
	}
	if (a_insert(r, -1, ALNBR, -1))
	{
		find_best_insert(r, 0, -1);
		src->low->bd = GOOD;
		simple_push(r, src, dst, pile);
	}
}
