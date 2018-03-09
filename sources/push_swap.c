/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/27 21:15:22 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static	int		error_checker(t_roll *r, int total, int i)
{
	while (++i < r->nb_a)
	{
		r->a.LBD & PUSH ? ++total : 0;
		rotate(NULL, &r->a, 0);
	}
	return (total);
}*/

void			push_swap(t_roll *r, char **p, int size)
{
//	ft_printf("{yellow}{bold}{underline}IN\tPUSH SWAP{eoc}\n");//////////////////
	t_tab		t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	find_best_rot(r, t, 0, -1);
	first_step(r, r->nb_a, -1, 0);
//	second_step(r, r->nb_a, -1, -1);
	int i = -1, total = 0;
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	while (++i < r->nb_a)////////////////////////////////////////////////////////
	{////////////////////////////////////////////////////////////////////////////
		if (ALBD & GOOD/* || ALBD & CHECK || ALBD & NO_CHECK*/)//////////////////
		{
			++total;///////////////////////////////////////////////
			ft_printf("{bold}ALNBR = %11d ", ALNBR);//
			ALBD & GOOD ? ft_printf("{green}GOOD{eoc}\t", ALNBR) : 0;//
			ALBD & CHECK ? ft_printf("{cyan}CHECK{eoc}\t", ALNBR) : 0;//
			ALBD & NO_CHECK ? ft_printf("{magenta}NO_CHECK{eoc}\t", ALNBR) : 0;//
			ft_printf("\n");//
		}
		rotate(NULL, &r->a, 0);//////////////////////////////////////////////////
	}////////////////////////////////////////////////////////////////////////////
	find_best_rotation(r, r->b_rot, 0);
	display_piles(r, &r->a, &r->b);
	ft_printf("size = %d dep = %d total = %d\n", r->size, r->dep, total);////////
}
