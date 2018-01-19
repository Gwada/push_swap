/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:26:28 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/19 19:51:20 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		display_piles(t_pile *a, t_pile *b)
{
	ft_printf("{black}{bold}Pile A{eoc} = ");
	if (!a)
		ft_printf("{red}[EMPTY]{eoc}\n");
	else
		display_pile(a, 'a');
	ft_printf("{black}{bold}Pile B{eoc} = ");
	if (!b)
		ft_printf("{red}[EMPTY]{eoc}\n");
	else
		display_pile(b, 'b');
	ft_printf("\n");
}

void		display_pile(t_pile *p, char pile)
{
	while(!p->root)
	{
		p->top->root ? ft_printf("{black}<-{eoc}") : 0;
		!p->top->root ? ft_printf("{yellow}<->{eoc}", pile) : 0;
		!p->root ? ft_printf("[%d]", p->nbr) : 0;
		p = p->low;
		p->root ? ft_printf("{black}->{eoc}\n", pile) : 0;
	}
}
