/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:47:19 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/18 19:21:51 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add_elem(t_tab *t, t_roll *r, int i)
{
	r->bd |= GOOD;
	while (!(r->bd & ERR) && ++i < r->size)
	{
//		ft_printf("in add\n\n");
		(i < r->size - 1) && (t[i].n == t[i + 1].n) ? r->bd |= ERR : 0;
		t[i].n != t[i].m.nbr ? r->bd &= ~GOOD : 0;

/*		ft_printf("r->nbr = %hhd\n", r->bd);
		ft_printf("r->nbr = %d\n", r->nbr);
		ft_printf("r->root = %s\n", r->root ? "root" : "(NULL)");
		ft_printf("r->top = %s\n", r->top ? "top" : "(NULL)");
		ft_printf("r->low = %s\n\n", r->low ? "low" : "(NULL)");

		ft_printf("t->nbr = %hhd\n", t->bd);
		ft_printf("t->nbr = %d\n", t->nbr);
		ft_printf("t->root = %s\n", t->root ? "root" : "(NULL)");
		ft_printf("t->top = %s\n", t->top ? "top" : "(NULL)");
		ft_printf("t->low = %s\n\n", t->low ? "low" : "(NULL)");*/

		if (!r->a.low && !r->a.top)
		{
			r->a.low = &t[i].m;
			r->a.top = &t[i].m;
			t[i].m.top = &r->a;
			t[i].m.low = &r->a;
		}
		else
		{
			t[i].m.low = &r->a;
			t[i].m.top = r->a.top;
			r->a.top->low = &t[i].m;
			r->a.top = &t[i].m;
		}
/*		ft_printf("r->nbr = %hhd\n", r->bd);
		ft_printf("r->nbr = %d\n", r->nbr);
		ft_printf("r->root = %s\n", r->root ? "root" : "(NULL)");
		ft_printf("r->top = %s\n", r->top ? "top" : "(NULL)");
		ft_printf("r->low = %s\n\n", r->low ? "low" : "(NULL)");

		ft_printf("t->nbr = %hhd\n", t->bd);
		ft_printf("t->nbr = %d\n", t->nbr);
		ft_printf("t->root = %s\n", t->root ? "root" : "(NULL)");
		ft_printf("t->top = %s\n", t->top ? "top" : "(NULL)");
		ft_printf("t->low = %s\n\n", t->low ? "low" : "(NULL)");*/
	}

	ft_printf("\nend add\n-----------------------\n");
}
