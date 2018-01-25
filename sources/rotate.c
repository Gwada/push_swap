/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:41:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/25 20:34:05 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate(t_roll *r, t_tab *t, t_pile *p, char pile)
{
	p->low->top = p->top;
	p->top->low = p->low;
	p->top = p->low;
	p->low->low->top = p;
	p->low = p->low->low;
	p->top->low = p;
	if (!t)
		return ;
	if (pile)
	{
		if (!(r->bd & COLOR))
			ft_printf("r%c\n", pile);
		else
			ft_printf("{green}r%c{eoc}\n", pile);
		if (r->bd & VISUAL)
			display_piles(r, &r->a, &r->b);
	}
}

void		r_rotate(t_roll *r, t_tab *t, t_pile *p, char pile)
{
	p->top->low = p->low;
	p->low->top = p->top;
	p->low = p->top;
	p->top->top->low = p;
	p->top = p->top->top;
	p->low->top = p;
	if (!t)
		return ;
	if (pile)
	{
		if (!(r->bd & COLOR))
			ft_printf("rr%c\n", pile);
		else
			ft_printf("{green}rr%c{eoc}\n", pile);
		r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
	}
}

void		d_rotate(t_tab *t, t_roll *r)
{
	rotate(NULL, t, &r->a, 0);
	rotate(NULL, t, &r->b, 0);
	if (!t)
		return ;
	!(r->bd & COLOR) ? ft_printf("rr\n") : ft_printf("{green}rr{eoc}\n");
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}

void		d_r_rotate(t_tab *t, t_roll *r)
{
	r_rotate(NULL, t, &r->a, 0);
	r_rotate(NULL, t, &r->a, 0);
	if (!t)
		return ;
	!(r->bd & COLOR) ? ft_printf("rrr\n") : ft_printf("{green}rrr{eoc}\n");
	r->bd & VISUAL ? display_piles(r, &r->a, &r->b) : 0;
}
