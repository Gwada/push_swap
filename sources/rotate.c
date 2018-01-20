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
	(void)t;
	(void)p;
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
	(void)t;
	(void)r;
}

void		d_r_rotate(t_tab *t, t_roll *r)
{
	(void)t;
	(void)r;
}
