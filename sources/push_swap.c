/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/05 05:56:28 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_roll *r, char **p, int size)
{
	t_tab	t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	r->bd &= ~COLOR;
	r->bd &= ~VISUAL;
	r->bd |= GOOD;
	find_best_rot(r, t, 0, -1);
	first_step(r, t, -1, 0);
	second_step(r, t, -1);
	last_step(r, -1);
//	int i = -1, test = 0;
//	while (++i < r->size)
//	{
//		ALNBR != (int)t[i].n ? ++test : 0;
//		rotate(NULL, &r->a, 0, 0);
//	}
//	!test ? ft_printf("{bold}{green}{underline}OK\n{eoc}") : 0;
//	test ? ft_printf("{bold}{red}{underline}KO!!!{eoc}") : 0;
}
