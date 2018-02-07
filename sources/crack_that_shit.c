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

/*static int	check_push(t_roll *r, int size, int i)
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
}*/

static	int	push_that(t_roll *r, int i)
{
	push(r, &r->a, &r->b, 'b');
	while (++i < (int)r->nb_a)
	{
		r->a.low->bd = 0;
		rotate(NULL, &r->a, 0);
	}
	return (0);
}

static	int	swap_that(t_roll *r, int i)
{
	r->a.low->bd &= ~SWAP;
	r->a.low->bd |= GOOD;
	r->a.low->low->bd |= GOOD;
	swap(r, &r->a, 'a');
	if (r->a.low->low->bd & R_ROT)
	{
		r_rotate(r, &r->a, 'a');
		r_rotate(r, &r->a, 'a');
	}
	else if (r->a.low->low->bd & ROT)
	{
		rotate(r, &r->a, 'a');
		rotate(r, &r->a, 'a');
	}
	while (++i < (int)r->nb_a)
	{
		r->a.low->bd = 0;
		rotate(NULL, &r->a, 0);
	}
	return (0);
}

int			go_to_best_rotation(t_roll *r, int size, int i)
{
//	ft_printf("{black}{bold}{underline}IN\tGO TO BEST ROTATION{eoc} size = %d\n", size);//
	int		t[size];

	while (++i < size)
	{
		t[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(t, size, 0, 0);
	find_best_combinaison(t, r, -1);
	find_best_sort(t, r, r->nb_a, -1);
	i = -1;//////////////////////////////////////////////////////////////////////
	while (++i < size)///////////////////////////////////////////////////////////
	{////////////////////////////////////////////////////////////////////////////
		ft_printf("[%d", r->a.LNBR);/////////////////////////////////////////////
		r->a.low->bd & ROT ? ft_printf("{magenta}(R){eoc}") : 0;///////////////////
		r->a.low->bd & R_ROT ? ft_printf("{yellow}(R_R){eoc}") : 0;//////////////
		r->a.low->bd & PUSH ? ft_printf("{red}(P){eoc}") : 0;////////////////////
		r->a.low->bd & SWAP ? ft_printf("{blue}(S){eoc}") : 0;///////////////////
		r->a.low->bd & GOOD ? ft_printf("{green}(G){eoc}") : 0;////////////////
		ft_printf("] ", r->a.LNBR);//////////////////////////////////////////////
		rotate(NULL, &r->a, 0);//////////////////////////////////////////////////
	}////////////////////////////////////////////////////////////////////////////
	ft_printf("\n\n");///////////////////////////////////////////////////////////
	int test = 1;
	while (r->a.low->bd & (ROT | R_ROT | PUSH))
	{
		test = 0;
		if (r->a.low->bd & PUSH/* && !check_push(r, r->nb_a, -1)*/)
			return (push_that(r, -1));
		else if (r->a.low->bd & SWAP)
			return (swap_that(r, -1));
		else if (r->a.low->bd & ROT)
			rotate(r, &r->a, 'a');
		else if (r->a.low->bd & R_ROT)
			r_rotate(r, &r->a, 'a');
	}
//	ft_printf("{black}{bold}{underline}END\tGO TO BEST ROTATION ret = %d{eoc}\n", test);//
	return (test);
}
