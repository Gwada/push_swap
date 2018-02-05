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

int				check_sort(t_pile *p, int size, int i)
{
//	ft_printf("\n{black}{bold}IN chek{eoc}\n");//////////////////////////////////
	int			tab[size];

	while (++i < size)
	{
		tab[i] = p->low->nbr;
		rotate(NULL, p, 'p');
		ft_printf("t[%d] = %d\t", i, tab[i], -1);////////////////////////////////////
	}
	ft_qsort(tab, size, 0, 0);
		ft_printf("\n");/////////////////////////////////////////////////////////
	//tmp = r->a.low ? r->a.low : NULL;
//	display_pile(NULL, p, 'p');//////////////////////////////////////////////////
	i = -1;
	while (++i < size)
//	{
	ft_printf("t[%d] = %d\t", i, tab[i]);////////////////////////////////////////
//		ft_printf("%d\t%d\n", (int)t[i].n, tmp->low->nbr);///////////////////////
//		tmp->low->bd & R_ROT ? ft_printf("rrot\n") : 0;//////////////////////////
//		if ((int)t[i].n != tmp->nbr)
//			break ;
//		tmp = tmp->low;
//	}
	ft_printf("\n");/////////////////////////////////////////////////////////////
	return (i == size ? GOOD : 0);
//	ft_printf("{black}{bold}end check{eoc}\n\n");////////////////////////////////
}

void			push_swap(t_roll *r, char **p, int size)
{
//	ft_printf("{yellow}{bold}{underline}IN\tPUSH SWAP{eoc}\n");//////////////////
	t_tab		t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
	go_to_best_rotation(r, t);
//	ft_printf("\n\n\n");/////////////////////////////////////////////////////////
//	ft_printf("return = %d\n", check_sort(&r->a, r->nb_a, -1));//////////////////
//	ft_printf("return = %d\n", check_sort(&r->b, r->nb_b, -1));//////////////////
//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
/*	int i = -1;
	while (++i < (int)r->nb_a)///////////////////////////////////////////////////
	{////////////////////////////////////////////////////////////////////////////
		ft_printf("[", r->a.low->nbr);///////////////////////////////////////////
		r->a.low->bd & GOOD ? ft_printf("{green}(GOOD){eoc}", r->a.low->nbr) : 0;//
		r->a.low->bd & PUSH ? ft_printf("{blue}(PUSH){eoc}", r->a.low->nbr) : 0;//
		r->a.low->bd & SWAP ? ft_printf("{magenta}(SWAP){eoc}", r->a.low->nbr) : 0;//
		r->a.low->bd & ROT ? ft_printf("{green}(ROT){eoc}", r->a.low->nbr) : 0;//
		r->a.low->bd & R_ROT ? ft_printf("{red}(R_ROT){eoc}", r->a.low->nbr) : 0;//
		ft_printf("%d] ", r->a.low->nbr);////////////////////////////////////////
		rotate(NULL, &r->a, 0);//////////////////////////////////////////////////
	}////////////////////////////////////////////////////////////////////////////
	ft_printf("\n");/////////////////////////////////////////////////////////////

//		check_sort(t, r, -1);////////////////////////////////////////////////////
//	r->bd & GOOD ? ft_printf("le tri est fini!!\n") : 0;/////////////////////////
	ft_printf("{yellow}{bold}{underline}END\tPUSH SWAP{eoc}\n");/////////////////*/
}
