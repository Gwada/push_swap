/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:32:24 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/27 21:22:22 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	find_max(t_roll *r)
{
	int			i;

	i = 0;
	r->a_max = !r->nb_a ? 0 : r->a.low->nbr;
	r->a_min = !r->nb_a ? 0 : r->a.low->nbr;
	while (++i <= r->nb_a)
	{
		rotate(NULL, &r->a, 0);
		r->a.low->nbr > r->a_max ? r->a_max = r->a.low->nbr : 0;
		r->a.low->nbr < r->a_min ? r->a_min = r->a.low->nbr : 0;
	}
	i = 0;
	r->b_max = !r->nb_b ? 0 : r->b.low->nbr;
	r->b_min = !r->nb_b ? 0 : r->b.low->nbr;
	while (++i <= r->nb_b)
	{
		rotate(NULL, &r->b, 0);
		r->b.low->nbr > r->b_max ? r->b_max = r->b.low->nbr : 0;
		r->b.low->nbr < r->b_min ? r->b_min = r->b.low->nbr : 0;
	}
}

static	void	find_best_insert(t_roll *r, t_pile *p, int value, char pile)
{
	int			i;
	int			max;
	int			min;
	int			rot;
	int			size;

	i = -1;
	rot = 0;
	size = pile == 'a' ? r->nb_a : r->nb_b;
	max = (pile == 'a' ? r->a_max : r->b_max);
	min = (pile == 'a' ? r->a_min : r->b_min);
	if (size > 1)
	{
		while (++i < size)
		{
			if (((value < min || value > max) && p->LNBR == max)
			|| (value < p->TNBR && value > p->LNBR))
				rot = i;
			rotate(NULL, p, 0);
		}
		if (rot > size / 2)
			while (rot++ < size)
				r_rotate(r, p, pile);
		else
			while (rot-- > 0)
				rotate(r, p, pile);
	}
}

void		simple_push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
//	ft_printf("{bold}{underline}{cyan}IN\tSIMPLE{eoc}\n");
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

//	ft_printf("{bold}{underline}{cyan}END\tSIMPLE{eoc}\n");
}

void			push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
//	ft_printf("\n{green}{bold}{underline}IN\tPUSH{eoc}\n");//////////////////////
	int			size;

	size = (pile == 'a' ? r->nb_b : r->nb_a);
	if (!(src->low) || src->low->root || !size)
		return ;
	find_best_insert(r, dst, ALNBR, pile);
	src->low->bd = GOOD;
	simple_push(r, src, dst, pile);
//	ft_printf("{green}{bold}{underline}END\tPUSH{eoc}\n\n");/////////////////////
}
