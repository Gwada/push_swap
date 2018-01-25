/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:26:28 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/25 20:34:01 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		display_piles(t_roll *r, t_pile *a, t_pile *b)
{
	display_pile(r, a, 'a');
	display_pile(r, b, 'b');
	ft_printf("\n");
}

void		display_pile(t_roll *r, t_pile *p, char pile)
{
	r->bd & COLOR ? ft_printf("{blue}{bold}Pile %c{eoc} = ", pile) : 0;
	!(r->bd & COLOR) ? ft_printf("Pile %c = ", pile) : 0;
	!p->low && r->bd & COLOR ? ft_printf("{red}[EMPTY]{eoc}\n") : 0;
	!p->low && !(r->bd & COLOR) ? ft_printf("[EMPTY]\n") : 0;
	if (p->low)
	{
		r->bd & COLOR ? ft_printf("{red}<-{eoc}") : ft_printf("<-");
		while(!p->low->root)
		{
			p->bd & GOOD ? ft_printf("{green}[%d]{eoc}", p->low->nbr) : 0;
			!(p->bd & GOOD) ? ft_printf("[%d]", p->low->nbr) : 0;
			p = p->low;
			if (!p->low->root)
				r->bd & COLOR ? ft_printf("{yellow}<->{eoc}", pile) : 0;
			(!p->low->root && !(r->bd & COLOR)) ? ft_printf("<->", pile) : 0;
		}
		r->bd & COLOR ? ft_printf("{red}->{eoc}\n") : ft_printf("->\n");
	}
}
