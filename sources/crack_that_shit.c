/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_best_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/27 21:18:21 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_rot(t_roll *r)
{
	r->a.low->bd &= ~ROT;
	if (r->a.low->bd & SWAP)
	{
		r->a.low->bd &= ~SWAP;
		r->a.low->low->bd = GOOD;
		swap(r, &r->a, 'a');
		rotate(r, &r->a, 'a');
	}
	rotate(r, &r->a, 'a');
}

static void	check_r_rot(t_roll *r)
{
	r->a.low->bd &= ~R_ROT;
	if (r->a.low->bd & SWAP)
	{
		r->a.low->bd &= ~SWAP;
		r->a.low->low->bd = GOOD;
		swap(r, &r->a, 'a');
		r_rotate(r, &r->a, 'a');
	}
	r_rotate(r, &r->a, 'a');
}

static int	check_push(t_roll *r, int size, int i)
{
	int		tab[size];

	while (++i < size)
	{
		tab[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(tab, size, 0, 0);
	i = 0;
	while (tab[i] != r->a.LNBR && i < size)
		++i;
	i = i + 1 >= size ? 0 : i + 1;
	if (size > 1 && tab[i] == r->a.low->LNBR)
		r->a.low->bd |= GOOD;
	if (r->a.low->bd & ROT)
		r->a.low->low->bd |= ROT;
	else if (r->a.low->bd & R_ROT)
		r->a.low->low->bd |= R_ROT;
	if ((r->a.LNBR < r->a.low->LNBR && ((r->a.LNBR > r->a.TNBR) || (r->a.TNBR == r->a_max))) || (r->a.low->bd & GOOD))
		r->a.low->bd &= ~PUSH;
	return (r->a.low->bd & PUSH ? 0 : 1);
}

void		go_to_best_rotation(t_roll *r, t_tab *t)
{
//	ft_printf("{black}{bold}{underline}IN\tGO TO BEST ROTATION{eoc}\n");/////////
	find_best_combinaison(t, r, -1);
	find_best_sort(t, r, r->size, -1);
	//while (r->a.low->bd & ROT || r->a.low->bd & R_ROT || r->a.low->bd & PUSH)
	while (r->a.low->bd & (ROT | R_ROT | PUSH))
	{
		if (r->a.low->bd & PUSH && !check_push(r, r->nb_a, -1))
			push(r, &r->a, &r->b, 'b');
		else if (r->a.low->bd & ROT)
			check_rot(r);
		else if (r->a.low->bd & R_ROT)
			check_r_rot(r);
	}
//	ft_printf("{black}{bold}{underline}END\tGO TO BEST ROTATION{eoc}\n");////////
}
