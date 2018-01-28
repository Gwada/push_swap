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

static	void	find_max(t_roll *r, int value)
{
//	ft_printf("{magenta}{bold}{underline}IN\tFIND MAX\n{eoc}");//////////////////
	int			i;

	i = -1;
	r->a_max = (!r->nb_a ? value : r->a_min);
	r->a_min = (!r->nb_a ? value : r->a_max);
	if (r->nb_a > 1)
	{
		while (++i < (int)r->nb_a)
		{
//			display_piles(r, &r->a, &r->b);//////////////////////////////////////
			r->a.low->nbr > r->a_max ? r->a_max = r->a.low->nbr : 0;
			r->a.low->nbr < r->a_min ? r->a_min = r->a.low->nbr : 0;
			rotate(NULL, &r->a, 0);
		}
	}
	i = -1;
	r->b_max = (r->nb_b == 1 ? value : r->b_min);
	r->b_min = (r->nb_b == 1 ? value : r->b_max);
	if (r->nb_b > 1)
	{
		while (++i < (int)r->nb_b)
		{
//			display_piles(r, &r->a, &r->b);//////////////////////////////////////
			r->b.low->nbr > r->b_max ? r->b_max = r->b.low->nbr : 0;
			r->b.low->nbr < r->b_min ? r->b_min = r->b.low->nbr : 0;
			rotate(NULL, &r->b, 0);
		}
	}
//	ft_printf("{magenta}{bold}{underline}END\tFIND MAX\n{eoc}");/////////////////
}

static	void	find_best_insert(t_roll *r, t_pile *p, int value, char pile)
{
	ft_printf("{magenta}{bold}{underline}IN\tFIND BEST INSERT\n{eoc}");//////////
	int			i;
	int			rot;
	int			size;

	i = -1;
	rot = 0;
	size = (int)(pile == 'a' ? r->nb_a : r->nb_b);
	display_piles(r, &r->a, &r->b);
	if (size < 2)
		return ;
//	ft_printf("rot = %d size = %d\n", rot, size);////////////////////////////////////////////////
	if (p->low->nbr < value)
	{
		while (p->low->nbr < value
		&& ((p->low->low->nbr < value) || (p->low->low->nbr > value)))
		{
			rotate(NULL, p, 0);
			++rot;
		}
		while (++i + rot < size)
			rotate(NULL, p, 0);
		display_piles(r, &r->a, &r->b);
	}
	else
	{
		while (p->low->nbr > value
		&& ((p->low->low->nbr > value) || (p->low->low->nbr < value)))
		{
			r_rotate(NULL, p, 0);
			++rot;
		}
		while (++i + rot < size)
			r_rotate(NULL, p, 0);
		display_piles(r, &r->a, &r->b);
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
	ft_printf("{magenta}{bold}{underline}END\tFIND BEST INSERT\n{eoc}");/////////
}

void			push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
//	ft_printf("{blue}{bold}{underline}IN\tPUSH\n{eoc}");/////////////////////////
	t_pile		*tmp;

	if (!(tmp = src->low) || tmp->low->root)
		return ;

//	ft_printf("r->nb_a = %d r->nb_b = %d\n", r->nb_a, r->nb_b);////////////////////////////////////////////////
	src->low->bd &= ~PUSH;
	dst->low ? find_best_insert(r, dst, tmp->nbr, pile) : 0;
	src->low = src->low->low;
	src->low->low->top = src;
	//dst->low ? find_best_insert(r, dst, tmp->nbr, pile) : 0;
	tmp->top = dst;
	tmp->low = dst->low ? dst->low : dst;
	dst->low ? (dst->low->top = tmp) : (dst->top = tmp);
	!dst->top ? (dst->top = tmp) : (dst->low = tmp);
	r->nb_a += (pile == 'a') ? 1 : -1;
	r->nb_b += (pile == 'b') ? 1 : -1;
	find_max(r, tmp->nbr);


	r->bd & COLOR ? ft_printf("{red}p%c\n{eoc}", pile) : 0;
	!(r->bd & COLOR) ? ft_printf("p%c\n", pile) : 0;
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
//	ft_printf("{blue}{bold}{underline}END\tPUSH\n{eoc}");////////////////////////
}
