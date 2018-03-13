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
	p->low->bd &= ~ROT;
	p->low->top = p->top;
	p->top->low = p->low;
	p->top = p->low;
	p->low->low->top = p;
	p->low = p->low->low;
	p->top->low = p;
	r ? ++r->dep : 0;
	if (!r || !pile)
		return ;
	if (r->bd & COLOR)
		ft_printf("{green}{bold}r%c{eoc}\n", pile);
	else
		ft_printf("r%c\n", pile);
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}

void		r_rotate(t_roll *r, t_pile *p, char pile)
{
	p->low->bd &= ~R_ROT;
	p->top->low = p->low;
	p->low->top = p->top;
	p->low = p->top;
	p->top->top->low = p;
	p->top = p->top->top;
	p->low->top = p;
	r ? ++r->dep : 0;
	if (!r || !pile)
		return ;
	if (r->bd & COLOR)
		ft_printf("{green}{bold}rr%c{eoc}\n", pile);
	else
		ft_printf("rr%c\n", pile);
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}

void		d_rotate(t_roll *r, int state)
{
	rotate(NULL, &r->a, 0);
	rotate(NULL, &r->b, 0);
	if (state ^ GOOD)
		return ;
	r->bd & COLOR ? ft_printf("{green}{bold}rr{eoc}\n") : ft_printf("rr\n");
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
	++r->dep;
}

void		d_r_rotate(t_roll *r, int state)
{
	r_rotate(NULL, &r->a, 0);
	r_rotate(NULL, &r->b, 0);
	if (state ^ GOOD)
		return ;
	r->bd & COLOR ? ft_printf("{green}{bold}rrr{eoc}\n") : ft_printf("rrr\n");
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
	++r->dep;
}
