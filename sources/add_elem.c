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

void		find_best(t_tab *t, t_roll *r, int val)
{
	int		i;
	int		rotate;

	i = -1;
	rotate = -1;
	(void)rotate;
	while (++i < r->size)
	{
		r_rotate(NULL, &r->a);
	//	while (++elem < r->size)
	//		cmp_tab_to_pile(t, r, &val);
		!(r->bd & GOOD) ? display_piles(r->a.low, NULL) : 0;
	}
	(void)t;
	(void)val;
}
