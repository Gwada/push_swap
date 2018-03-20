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

void		push_swap(t_roll *r, char **p, int size)
{
//	ft_printf("{yellow}{bold}{underline}IN\tPUSH SWAP{eoc}\n");//////////////////
	t_tab	t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	r->fd = open("push_swap.txt", O_RDONLY | O_CREAT);
	ft_printf("\n");/////////////////////////////////////////////////////////////
	find_best_rot(r, t, 0, -1);
	first_step(r, t, -1, 0);
	display_piles(r, &r->a, &r->b);
	fixe_push(r, -1, 0, 0);
	int i = -1, nb_c = 0, nb_n_c = 0;
	while (++i < r->nb_a)
	{
		ALBD & CHECK ? ++nb_c : 0;
		ALBD & NO_CHECK ? ++nb_n_c : 0;
		rotate(NULL, &r->a, 0);
	}
	display_piles(r, &r->a, &r->b);
	second_step(r);
/*	int i = -1, total = 0;
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	while (++i < r->nb_a)////////////////////////////////////////////////////////
	{////////////////////////////////////////////////////////////////////////////
		ALBD & GOOD ? ++total : 0;///////////////////////////////////////////////
		ALBD & GOOD ? ft_printf("{bold}ALNBR = %11d ", ALNBR) : 0;//
		ALBD & GOOD ? ft_printf("{green}GOOD{eoc}\n", ALNBR) : 0;//
		rotate(NULL, &r->a, 0);//////////////////////////////////////////////////
	}////////////////////////////////////////////////////////////////////////////
	find_best_rotation(r, r->b_rot, 0);*/
//	ft_printf("size = %d b_rot = %d total = %d\n", r->size, r->b_rot, total);////////
	display_piles(r, &r->a, &r->b);
//	ft_dprintf(r->fd, "test\n");
	ft_printf("nb_c = %d nb_n_c = %d\n", nb_c, nb_n_c);
}
