/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:26:28 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/01 20:58:50 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	display_pile(t_roll *r, t_pile *p, char pile)
{
	r->bd & COLOR ? ft_printf("{blue}{bold}Pile %c{eoc} = ", pile) : 0;
	!(r->bd & COLOR) ? ft_printf("Pile %c = ", pile) : 0;
	!p->low && r->bd & COLOR ? ft_printf("{red}[EMPTY]{eoc}\n") : 0;
	!p->low && !(r->bd & COLOR) ? ft_printf("[EMPTY]\n") : 0;
	if (p->low)
	{
		r->bd & COLOR ? ft_printf("{red}<-{eoc}") : ft_printf("<-");
		while (!p->low->root)
		{
			if (p->low->bd & GOOD)
				ft_printf("{green}[%d]{eoc}", p->LNBR);
			else if (p->low->bd & CHECK)
				ft_printf("{cyan}[%d]{eoc}", p->LNBR);
			else if (p->low->bd & NO_CHECK)
				ft_printf("{magenta}[%d]{eoc}", p->LNBR);
			else
				ft_printf("[%d]", p->low->nbr);
			p = p->low;
			!p->low->root ? ft_printf("<->", pile) : 0;
		}
		r->bd & COLOR ? ft_printf("{red}->{eoc}\n") : ft_printf("->\n");
	}
}

void			display_piles(t_roll *r, t_pile *a, t_pile *b)
{
	display_pile(r, a, 'a');
	display_pile(r, b, 'b');
	ft_printf("r->dep = %d\n\n", r->dep);
}
