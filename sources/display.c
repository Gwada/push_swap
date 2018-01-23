/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:26:28 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/20 19:00:37 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		display_piles(t_pile *a, t_pile *b)
{
	display_pile(a, 'A');
	display_pile(b, 'B');
	ft_printf("\n");
}

void		display_pile(t_pile *p, char pile)
{
	ft_printf("{blue}{bold}Pile %c{eoc} = ", pile);
	if (!p->low)
		ft_printf("{red}[EMPTY]{eoc}\n");
	else
	{
		ft_printf("{black}<-{eoc}");
		while(!p->low->root)
		{
			if (p->bd & GOOD)
				ft_printf("{green}[%d]{eoc}", p->low->nbr);
			else
				ft_printf("[%d]", p->low->nbr);
			p = p->low;
			!p->low->root ? ft_printf("{yellow}<->{eoc}", pile) : 0;
		}
		ft_printf("{black}->{eoc}\n", pile);
	}
}
