/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:47:19 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/20 20:13:33 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add_elem(t_tab *t, t_roll *r, int i)
{
	r->bd |= GOOD;
	while (!(r->bd & ERR) && ++i < r->size)
	{
		(i < r->size - 1) && (t[i].n == t[i + 1].n) ? r->bd |= ERR : 0;
		t[i].n != t[i].m.nbr ? (r->bd &= ~GOOD) : (t[i].m.bd |= GOOD);
		t[i].n == t[i].m.nbr ? ++r->cor : 0;
		t[i].m.nbr == r->a_max ? t[i].m.bd |= MAX : 0;
		t[i].m.nbr == r->a_min ? t[i].m.bd |= MIN : 0;
		t[i].m.pos = i;
		t[i].m.low = &r->a;
		t[i].m.top = !r->a.top ? &r->a : r->a.top;
		!r->a.low ? (r->a.low = &t[i].m) : (r->a.top->low = &t[i].m);
		r->a.top = &t[i].m;
	}
}

void		find_best(t_tab *t, t_roll *r, int val)
{
	int		rotate;
	int		elem;

	ft_printf("in find\n");
	rotate = -1;
	while (++rotate < r->size)
	{
		r_rotate(NULL, &r->a);
		elem = -1;
	//	while (++elem < r->size)
	//		cmp_tab_to_pile(t, r, &val);
		display_piles(r->a.low, NULL);
	}
	(void)t;
	(void)val;
}
