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

void		go_to_best_rotation(t_roll *r, t_tab *t)
{
//	ft_printf("{black}{bold}{underline}IN\tGO TO BEST ROTATION{eoc}\n");/////////
	find_best_combinaison(t, r, -1);
	find_best_sort(t, r, r->size, -1);
	while (r->a.low->bd & ROT || r->a.low->bd & R_ROT || r->a.low->bd & PUSH)
	{
		if (r->a.low->bd & PUSH)
		{
			if (r->a.low->bd & ROT)
				r->a.low->low->bd |= ROT;
			else if (r->a.low->bd & R_ROT)
				r->a.low->low->bd |= R_ROT;
			if (r->a.low->nbr < r->a.low->low->nbr && r->a.low->nbr > r->a.top->nbr)
				r->a.low->bd &= ~PUSH;
			else
				push(r, &r->a, &r->b, 'b');
		}
		if (r->a.low->bd & ROT)
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
		else
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
	}
//	ft_printf("{black}{bold}{underline}END\tGO TO BEST ROTATION{eoc}\n");////////
}
