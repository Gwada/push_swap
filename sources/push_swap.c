/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/01 20:20:43 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_roll *r, char **p, int size)
{
	t_tab	t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
//	r->bd &= ~COLOR;
//	r->bd &= ~VISUAL;
	find_best_rot(r, t, 0, -1);
	first_step(r, t, -1, 0);
	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
	second_step(r, t, -1);
	last_step(r, -1);

//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
	int i = -1, test = 0;
	while (++i < r->nb_a)
	{
//				ft_printf("{bold}{green}t[%3d].n = %11ld\t{eoc}", i, t[i].n);
//				ft_printf("{bold}ALNBR = %11d\t{eoc}", ALNBR);
//				ALBD & GOOD ? ft_printf("{green}{bold}ALBD & GOOD{eoc}\t") : 0;
//				(int)t[i].n == ALNBR ? ft_printf("{green}{bold}GOOD{eoc}\n") : ft_printf("{red}{bold}ERROR !!!{eoc}\n");
		(int)t[i].n != ALNBR ? ++test : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
	ft_printf("{bold}{yellow}size = %d\tr->dep = %d r->pvt = %d\t{eoc}", r->size, r->dep, r->pvt);///
	test ? ft_printf("{red}{bold}{underline}error!!{eoc}\n") : 0;////////////////
	!test ? ft_printf("{green}{bold}{underline}TRI OK!!{eoc}\n") : 0;////////////
}
