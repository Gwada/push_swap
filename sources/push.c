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
	while (++i <= (int)r->nb_a)
	{
		rotate(NULL, &r->a, 0);
		r->a.low->nbr > r->a_max ? r->a_max = r->a.low->nbr : 0;
		r->a.low->nbr < r->a_min ? r->a_min = r->a.low->nbr : 0;
	}
	i = 0;
	r->b_max = !r->nb_b ? 0 : r->b.low->nbr;
	r->b_min = !r->nb_b ? 0 : r->b.low->nbr;
	while (++i <= (int)r->nb_b)
	{
		rotate(NULL, &r->b, 0);
		r->b.low->nbr > r->b_max ? r->b_max = r->b.low->nbr : 0;
		r->b.low->nbr < r->b_min ? r->b_min = r->b.low->nbr : 0;
	}
}

static	void	find_best_insert(t_roll *r, t_pile *p, int value, char pile)
{
//	ft_printf("{magenta}{bold}{underline}IN\tFIND BEST INSERT\n{eoc}");//////////
	int			i;
	int			max;
	int			min;
	int			rot;
	int			size;

	i = -1;
	rot = 0;
	size = (int)(pile == 'a' ? r->nb_a : r->nb_b);
	max = (pile == 'a' ? r->a_max : r->b_max);
	min = (pile == 'a' ? r->a_min : r->b_min);
	if (size < 2 || (value > p->LNBR && value < p->TNBR))
		return ;
	while (++i < size)
	{
		if ((value > p->LNBR && ((value < p->TNBR) || (p->LNBR == max)))
		|| (p->TNBR == min && value < p->TNBR))
			rot = i;
		rotate(NULL, p, 0);
	}
	if (rot > size / 2)
		while (rot++ < size)
			r_rotate(r, p, pile);
	else
		while (rot-- > 0)
			rotate(r, p, pile);
//	ft_printf("{magenta}{bold}{underline}END\tFIND BEST INSERT\n{eoc}");/////////
}

void			push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
//	ft_printf("{blue}{bold}{underline}IN\tPUSH\n{eoc}");/////////////////////////
	t_pile		*tmp;

	if (!(src->low) || src->low->root)
		return ;
	tmp = src->low;
	tmp->bd &= ~PUSH;
	find_best_insert(r, dst, tmp->nbr, pile);
	src->low = src->low->low;
	src->low->low->top = src;
	tmp->top = dst;
	tmp->low = dst->low ? dst->low : dst;
	dst->low ? (dst->low->top = tmp) : (dst->top = tmp);
	!dst->top ? (dst->top = tmp) : (dst->low = tmp);
	r->nb_a += (pile == 'a') ? 1 : -1;
	r->nb_b += (pile == 'b') ? 1 : -1;
	find_max(r);

	r->bd & COLOR ? ft_printf("{red}p%c\n{eoc}", pile) : 0;
	!(r->bd & COLOR) ? ft_printf("p%c\n", pile) : 0;
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
//	ft_printf("{blue}{bold}{underline}END\tPUSH\n{eoc}");////////////////////////
}
