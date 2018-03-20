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
			if (((ALNBR < min || ALNBR > max) && BLNBR == min)
			|| (ALNBR > BTNBR && ALNBR < BLNBR))
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
	ft_printf("\n{yellow}{bold}{underline}IN\tA_INSERT{eoc}\n");////////////////////////////////
//	ft_printf("nb_a = %d nb_b = %d\n\n", r->nb_a, r->nb_b);////////
	int			min;
	int			max;
	int			rot_a;
	int			rot_b;
	int			n_dep_l;
	int			n_dep_t;
	int			b_rot_a;

	rot_a = -1;
	rot_b = -1;

	// Calcule nb dep min pour insertion dans b
	while (++i < r->nb_b)
	{
		if (rot_b == -1
		&& ((BTNBR > BLNBR && (value > BTNBR || value < BLNBR))
		|| (BTNBR < BLNBR && value > BTNBR && value < BLNBR)))
			rot_b = i > (r->nb_b / 2) ? r->nb_b - i : i;
		rotate(NULL, &r->b, 0);
	}
//	ft_printf("{underline}{bold}insertion dans b{runderline}{eoc}\n");
//	ft_printf("%d %s + 1 push\n\n", rot_b, rot_b < 2 ? "deplacement" : "deplacements");

	// Calcule nb dep min pour insertion dans a
	i = -1;
	while (++i < r->nb_a)
	{
		if (ATBD & GOOD && rot == -1)
		{
			min = ATNBR;
			rot_a = r->nb_a - i;
			while (ALBD ^ GOOD && --rot_a != r->nb_a + 1)
				rotate(NULL, &r->a, 0);
			max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			if ((min > max && (value > min || value < max))
			|| (min < max && value > min && value < max))
				rot = i <= r->nb_a / 2 ? i - 1 : i;
		}
		rotate(NULL, &r->a, 0);
	}

//	ft_printf("{underline}{bold}insertion dans a{runderline}{eoc}\t");
//	ft_printf("min = %d max = %d ATNBR = %d\n\n", min, max, ATNBR);

	n_dep_l = rot > (r->nb_a / 2) ? r->nb_a - rot : rot;
	n_dep_t = rot_a > (r->nb_a / 2) ? r->nb_a - rot_a : rot_a;

//	ft_printf("{underline}{bold}{cyan}LOW{runderline}{eoc}\nrot = %d\n", rot);
//	ft_printf("%d ", n_dep_l);
//	ft_printf("deplacement(s) + 2 push\n\n");

//	ft_printf("{underline}{bold}{yellow}TOP{runderline}{eoc}\n");
//	ft_printf("rot_a = %d\n", (rot_a > r->nb_a / 2 ? ++rot_a : rot_a));
//	ft_printf("%d deplacement(s) + 2 push\n\n", n_dep_t);

	b_rot_a = n_dep_t < n_dep_l ? n_dep_t : n_dep_l;

	ft_printf("n_dep_a = %d\n", b_rot_a);
	ft_printf("n_dep_b = %d\n", rot_b);
	if (b_rot_a > 1 && b_rot_a * 2 + 2 <= rot_b + 1)
	{
		ft_printf("{red}{bold}{underline}INSERTION DANS A\n");
		ft_printf("rot = %d\trot_a = %d\tn_dep_t = %d\tn_dep_l = %d\n", rot, rot_a, n_dep_t, n_dep_l);
		rot = n_dep_t < n_dep_l ? rot_a : rot;
		simple_push(r, &r->a, &r->b, 'b');
	//	display_piles(r, &r->a, &r->b);
		if (rot <= r->nb_a / 2)
			while (ATNBR != min)
			{
				rotate(r, &r->a, 'a');
	//			display_piles(r, &r->a, &r->b);
			}
		else
			while (ALNBR != max)
			{
				r_rotate(r, &r->a, 'a');
	//			display_piles(r, &r->a, &r->b);
			}
		BLBD = GOOD;
		simple_push(r, &r->b, &r->a, 'a');
	//	display_piles(r, &r->a, &r->b);
		ft_printf("{bold}{green}insertion -> a\n{yellow}{underline}END\tA_INSERT{eoc}\n\n");/////////////////
		return (0);
	}
	ft_printf("{yellow}{bold}{underline}END\tA_INSERT insertion -> b{eoc}\n\n");/////////////////
	return (1);
}

void			push(t_roll *r, t_pile *src, t_pile *dst, char pile)
{
//	ft_printf("{red}{bold}{underline}IN\tPUSH{eoc}\n");//////////////////////
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
//	ft_printf("{red}{bold}{underline}END\tPUSH{eoc}\n");/////////////////////
}
