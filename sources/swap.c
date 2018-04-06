/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:16:09 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/06 17:22:19 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_roll *r, t_pile *p, char pile)
{
	t_pile	*tmp;

	if (!p->low || p->low->root
	|| (pile == 'a' && r->nb_a < 2) || (pile == 'b' && r->nb_b < 2))
		return ;
	p->LBD = GOOD;
	p->low->LBD = GOOD;
	tmp = p->low;
	p->low->low->top = &r->a;
	p->low = p->low->low;
	tmp->low = p->low->low;
	tmp->top = p->low;
	tmp->top->low = tmp;
	tmp->low->top = tmp;
	r ? ++r->dep : 0;
	if (!r || !pile)
		return ;
	if (r->bd && r->bd & COLOR)
		ft_printf("{magenta}{bold}s%c{eoc}\n", pile);
	else if (r->bd && r->bd ^ COLOR)
		ft_printf("s%c\n", pile);
	r->bd && r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
	r->b_rot = 0;
}

void		s_swap(t_roll *r)
{
	swap(NULL, &r->a, 0);
	swap(NULL, &r->b, 0);
	++r->dep;
	if (r->bd && r->bd & COLOR)
		ft_printf("{magenta}{bold}ss{eoc}\n");
	else if (r->bd && r->bd & COLOR)
		ft_printf("ss\n");
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
	r->b_rot = 0;
}
