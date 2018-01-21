/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:41:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/20 20:13:46 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate(t_tab *t, t_pile *p)
{
	p->low->top = p->top;
	p->top->low = p->low;
	p->top = p->low;
	p->low->low->top = p;
	p->low = p->low->low;
	p->top->low = p;
	if (!t)
		return ;
}

void		r_rotate(t_tab *t, t_pile *p)
{
	p->top->low = p->low;
	p->low->top = p->top;
	p->low = p->top;
	p->top->top->low = p;
	p->top = p->top->top;
	p->low->top = p;
	if (!t)
		return ;
}


void		d_rotate(t_tab *t, t_roll *r)
{
	rotate(t, &r->a);
	rotate(t, &r->b);
	if (!t)
		return ;
}

void		d_r_rotate(t_tab *t, t_roll *r)
{
	r_rotate(t, &r->a);
	r_rotate(t, &r->a);
}
