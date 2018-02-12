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
	ft_printf("{green}{bold}{underline}IN\tPUSH{eoc}\n");//////////////////////
	t_pile		*tmp;

	if (!(src->low) || src->low->root)
		return ;
	if (!find_best_push(r, src->LNBR, 0, 0))
	{
		tmp = src->low;
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
		tmp->bd = GOOD;
		r->bd & COLOR ? ft_printf("{red}p%c\n{eoc}", pile) : 0;
		!(r->bd & COLOR) ? ft_printf("p%c\n", pile) : 0;
		r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
	}

	ft_printf("{green}{bold}{underline}END\tPUSH{eoc}\n\n");/////////////////////
}

void		simple_push(t_roll*r, t_pile *src, t_pile *dst, char pile)
{
	t_pile		*tmp;

	tmp = src->low;
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
}

int			find_best_push(t_roll *r, int value, int rot_a, int rot_b)
{
	ft_printf("{red}{bold}IN\tFIND BEST PUSH{eoc} value = %d\n\n", value);//
	ft_printf("{magenta}r->nb_a = [%3d]\tr->nb_b = [%3d]{eoc}\n\n", r->nb_a, r->nb_b);
	int		i;
	int		i_cor;
	int		i_incor;
	int		t1[r->nb_a];

	i = -1;
	while (++i < r->nb_a)
	{
		t1[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(t1, r->nb_a, 0, 0);
	find_best_combinaison(t1, r, -1);
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	i = -1;
	while (++i < r->size)
	{
		if (i >= r->nb_a && i >= r->nb_b)
			break ;
		if (i < r->nb_a)
		{
			t1[i] == value ? i_cor = i : 0;
			r->a.LNBR == value ? i_incor = i : 0;
			ft_printf("{yellow}t1[%2d]{eoc} = [{green}%10d{eoc}]\t {magenta}p->LNBR = [%10d]{eoc} ", i, t1[i], r->a.LNBR);
			if (r->a.low->bd & GOOD)
				ft_printf("{green}GOOD{eoc} ");
			if (r->a.low->bd & PUSH)
				ft_printf("{red}PUSH{eoc} ");
			if (r->a.low->bd & SWAP)
				ft_printf("{yellow}SWAP{eoc} ");
			rotate(NULL, &r->a, 0);
			ft_printf("\n");
		}
		if (i < r->nb_b)
		{
			if ((value > r->b.LNBR && ((value < r->b.TNBR) || (r->b.LNBR == r->b_max)))
			|| (r->b.TNBR == r->b_min && value < r->b.TNBR))
				rot_b = i;
			rotate(NULL, &r->b, 0);
		}
	}
	ft_printf("\n");

	rot_a = i_cor > i_incor ? i_cor - i_incor : i_incor - i_cor;
	rot_a > r->nb_a / 2 ? rot_a = r->nb_a - rot_a : 0;

	find_best_rotation(r, r->b_rot, 0);
	rot_b > r->nb_b / 2 ? rot_b = r->nb_b - rot_b : 0;

	ft_printf("r->b_rot = [%2d]\n", r->b_rot);
	ft_printf("nb_a = [%2d] rot_a = [%2d]\tnb_b = [%2d] rot_b = [%2d]\n", r->nb_a, rot_a + 2, r->nb_b, rot_b + 1);

	if ((rot_a += 2) <= ++rot_b)
	{
		ft_printf("{yellow}{underline}{bold}insetion dans a!!!{eoc}\n");
		if ((i_cor > i_incor && (r->nb_a - (i_cor - i_incor)) >= (r->nb_a / 2))
		|| (i_incor > i_cor && (r->nb_a - (i_incor - i_cor)) < (r->nb_a / 2)))
		{
			ft_printf("test 1\n");
			if (rot_a == 3)
			{
				r_rotate(r, &r->a, 'a');
				swap(r, &r->a, 'a');
				r->a.low->bd = 0;
			}
			else
			{
				simple_push(r, &r->a, &r->b, 'b');
				while (rot_a-- - 2)
				{
					rotate(r, &r->a, 'a');
					r->a.low->bd & SWAP ? swap(r, &r->a, 'a') : 0;
				}
				simple_push(r, &r->b, &r->a, 'a');
				r->a.low->bd |= GOOD;
			}
		}
		else
		{
			ft_printf("test 2\n");
			if (rot_a > 3)
			{
				simple_push(r, &r->a, &r->b, 'b');
				while (rot_a-- - 2)
				{
					r_rotate(r, &r->a, 'a');
					r->a.low->bd & SWAP ? swap(r, &r->a, 'a') : 0;
				}
				simple_push(r, &r->b, &r->a, 'a');
				r->a.low->bd |= GOOD;
			}
			else
			{
				rotate(r, &r->a, 'a');
				swap(r, &r->a, 'a');
				r->a.low->bd = 0;
			}
		}
		ft_printf("{red}{underline}{bold}END\tFIND BEST PUSH{eoc}\n\n");/////////////
		return (1);
	}
	ft_printf("{red}{bold}END\tFIND BEST PUSH{eoc}\n\n");/////////////
	return (0);
}
