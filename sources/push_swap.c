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
//	ft_printf("{black}{bold}IN check_sort{eoc}\n");//////////////////////////////
	int			verif;
	int			tab[size];

	verif = 0;
	while (++i < size)
	{
		tab[i] = p->LNBR;
		rotate(NULL, p, 0);
	}
	ft_qsort(tab, size, 0, 0);
	i = -1;
	while (++i < size)
	{
		tab[i] != p->LNBR ? verif = 1 : 0;
		rotate(NULL, p, 0);
	}
//	ft_printf("{black}{bold}end check verif = %d{eoc}\n\n", verif);//////////////
	return (verif);
}

void			go_to_last_value(t_roll *r, int last)
{
	while (r->a.LNBR != last)
	{
		rotate(r, &r->a, 'a');
	}
}

void			push_swap(t_roll *r, char **p, int size)
{
//	ft_printf("{yellow}{bold}{underline}IN\tPUSH SWAP{eoc}\n");//////////////////
	t_tab		t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
//	int test = 0;
//	ft_printf("{yellow}{bold}{underline}WHILE{eoc}\n\n");////////////////////////
	while (check_sort(&r->a, r->nb_a, -1))
	{
		if (/*++test == 42 || */go_to_best_rotation(r, r->nb_a, -1))
		{
//			display_piles(r, &r->a, &r->b);//////////////////////////////////////
			break ;
		}
//		display_piles(r, &r->a, &r->b);//////////////////////////////////////////
//		ft_printf("{blue}{underline}{bold}END BOUCLE{eoc}\n");///////////////////
//		ft_printf("-------------------------------------------------\n\n\n");////
	}
	go_to_last_value(r, r->a.TNBR);
//		display_piles(r, &r->a, &r->b);//////////////////////////////////////////
//	test >= 42 ? ft_printf("{red}{bold}test == 42\n{eoc}") : 0;
//	ft_printf("{yellow}{bold}{underline}END WHILE{eoc}\n");////////////////////
//	ft_printf("{yellow}{bold}{underline}END\tPUSH SWAP{eoc}\n");/////////////////
}
