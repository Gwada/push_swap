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

static	void	find_best_insert(t_roll *r, t_pile *p, int value, char pile)
{
	int			i;
	int			max;
	int			min;
	int			rot;

	i = -1;
	rot = 0;
	max = (pile == 'a' ? r->a_max : r->b_max);
	min = (pile == 'a' ? r->a_min : r->b_min);
	if ((pile == 'a' ? r->nb_a : r->nb_b) > 1)
	{
		while (++i < (pile == 'a' ? r->nb_a : r->nb_b))
		{
			if (((value < min || value > max) && p->LNBR == max)
			|| (value < p->TNBR && value > p->LNBR))
				rot = i;
			rotate(NULL, p, 0);
		}
		if (rot > (pile == 'a' ? r->nb_a : r->nb_b) / 2)
			while (rot++ < (pile == 'a' ? r->nb_a : r->nb_b))
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

static	int		a_insert(t_roll *r, int i, int value, int rot)
{
	ft_printf("\n{yellow}{bold}{underline}IN\tA_INSERT{eoc} nb_a = %d nb_b = %d\n", r->nb_a, r->nb_b);//////////////////
	int			min;
	int			max;
	int			rot_b;

	rot_b = 0;
	while (++i < r->nb_b)
	{
		if (rot == -1 && (((value < r->b_min || value > r->b_max) && BLNBR == r->b_max) || (value < BTNBR && value > BLNBR)))
				rot_b = i;
		rotate(NULL, &r->b, 0);
	}
	rot_b > (r->nb_b / 2) ? rot_b = r->nb_b - rot_b : 0;
	i = -1;
	while (++i < r->nb_a)
	{
		if (ATBD & GOOD)
		{
			rot == -1 ? min = ATNBR : 0;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			rot == -1 ? max = ALNBR : 0;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			if (rot == -1 && ((value > ATNBR && (value < max || ATNBR > max)) || (value < ATNBR && value < max && max < min)))
				rot = i;
		}
		rotate(NULL, &r->a, 0);
	}
	value = rot > (r->nb_a / 2) ? r->nb_a - rot : rot;
	ft_printf("test 1 rot = %d rot_b = %d\n", value, rot_b);
	if (value > 1 && value <= rot_b + 1)
	{
		ft_printf("{magenta}{bold}{underline}insertion dans a{eoc}\n");
		simple_push(r, &r->a, &r->b, 'b');
		if (rot <= r->nb_a / 2)
			while (ATNBR != min)
				rotate(r, &r->a, 'a');
		else
			while (ALNBR != max)
				r_rotate(r, &r->a, 'a');
		BLBD = GOOD;
		simple_push(r, &r->b, &r->a, 'a');
		ft_printf("{yellow}{bold}{underline}END\tA_INSERT{eoc}\n\n");/////////////////
		return (0);
	}
	ft_printf("{yellow}{bold}{underline}END\tA_INSERT{eoc}\n\n");/////////////////
	return (1);
}

void			push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
//	ft_printf("{red}{bold}{underline}IN\tPUSH{eoc}\n");//////////////////////
	int			size;

	size = (pile == 'a' ? r->nb_b : r->nb_a);
	if (!(src->low) || src->low->root || !size)
		return ;
	if (a_insert(r, -1, ALNBR, -1))
	{
		find_best_insert(r, dst, ALNBR, pile);
		src->low->bd = GOOD;
		simple_push(r, src, dst, pile);
	}
//	ft_printf("{red}{bold}{underline}END\tPUSH{eoc}\n");/////////////////////
}
