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

static	void	find_best_insert(t_roll *r, t_pile *p, int value, char pile)
{
//	ft_printf("{blue}{bold}{underline}IN\tFIND BEST INSERT\n{eoc}");/////////////
	int			i;
	int			rot;
	int			size;

	i = -1;
	rot = 0;
	size = (int)(pile == 'a' ? r->nb_a : r->nb_b);
//	ft_printf("rot = %d\n", rot);////////////////////////////////////////////////
	while (++i < size)
	{
		if (value > p->low->nbr && value < p->top->nbr)
			rot = i;
		rotate(NULL, p, 0);
	}
//	ft_printf("rot = %d\n", rot);////////////////////////////////////////////////
	if (rot > size / 2)
		while (rot++ < size)
		{
			rotate(r, p, pile);
		}
	else
		while (rot-- >= 0)
		{
			r_rotate(r, p, pile);
		}
//	ft_printf("{blue}{bold}{underline}END\tFIND BEST INSERT\n{eoc}");////////////
}

void			push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
//	ft_printf("{blue}{bold}{underline}IN\tPUSH\n{eoc}");
	t_pile		*tmp;

	if (!(tmp = src->low) || tmp->low->root)
		return ;
//	ft_printf ("r->nb_a = %d\tr->nb_b = %d\n", (int)r->nb_a, (int)r->nb_b);
	r->nb_a += (pile == 'a') ? 1 : -1;
	r->nb_b += (pile == 'b') ? 1 : -1;
//	ft_printf ("r->nb_a = %d\tr->nb_b = %d\n", (int)r->nb_a, (int)r->nb_b);
	src->low->bd &= ~PUSH;
	src->low = src->low->low;
	src->low->low->top = src;
	dst->low ? find_best_insert(r, dst, src->low->nbr, pile) : 0;
	tmp->top = dst;
	tmp->low = dst->low ? dst->low : dst;
	dst->low ? (dst->low->top = tmp) : (dst->top = tmp);
	!dst->top ? (dst->top = tmp) : (dst->low = tmp);
	if (r->bd & COLOR)
		ft_printf("{red}p%c\n{eoc}", pile);
	else
		ft_printf("p%c\n", pile);
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
//	ft_printf("{blue}{bold}{underline}END\tPUSH\n{eoc}");
}
