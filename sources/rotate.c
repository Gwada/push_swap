/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:41:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/27 21:08:05 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate(t_roll *r, t_pile *p, char pile)
{
	if ((pile == 'a' && r->nb_a == 1) || (pile == 'b' && r->nb_b == 1))
		return ;
	if (r && r->nb_b > 0 && pile == 'a' && BLBD & GOOD)
		if (calibrate_rot(r, r->b_rot < 1 ? 1 : r->b_rot))
			return (d_rotate(r, ROT));
	p->low->bd &= ~ROT;
	p->low->top = p->top;
	p->top->low = p->low;
	p->top = p->low;
	p->low->low->top = p;
	p->low = p->low->low;
	p->top->low = p;
	if (!r || !pile)
		return ;
	++r->dep;
	if (r->bd & COLOR)
		ft_printf("{green}{bold}r%c{eoc}\n", pile);
	else
		ft_printf("r%c\n", pile);
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}

void		r_rotate(t_roll *r, t_pile *p, char pile)
{
	if ((pile == 'a' && r->nb_a == 1) || (pile == 'b' && r->nb_b == 1))
		return ;
	if (r && r->nb_b > 0 && pile == 'a' && BLBD & GOOD)
		if (calibrate_rot(r, r->b_rot < 1 ? 1 : r->b_rot))
			return (d_rotate(r, R_ROT));
	p->low->bd &= ~R_ROT;
	p->top->low = p->low;
	p->low->top = p->top;
	p->low = p->top;
	p->top->top->low = p;
	p->top = p->top->top;
	p->low->top = p;
	if (!r || !pile)
		return ;
	++r->dep;
	if (r->bd & COLOR)
		ft_printf("{green}{bold}rr%c{eoc}\n", pile);
	else
		ft_printf("rr%c\n", pile);
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}

void		d_rotate(t_roll *r, int state)
{
	if (state & ROT)
	{
		rotate(NULL, &r->a, 0);
		rotate(NULL, &r->b, 0);
		r->bd & COLOR ? ft_printf("{green}{bold}rr{eoc}\n") : ft_printf("rr\n");
	}
	else if (state & R_ROT)
	{
		r_rotate(NULL, &r->a, 0);
		r_rotate(NULL, &r->b, 0);
		r->bd & COLOR ? ft_printf("{green}{bold}rrr{eoc}\n") : ft_printf("rrr\n");
	}
	++r->dep;
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}
