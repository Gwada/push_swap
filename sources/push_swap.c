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

void			error_verif(t_roll *r, int size, int i, int j)
{
//	ft_printf("{black}{bold}IN\tERROR VERIF{eoc}\n");////////////////////////////
	int			total;
	int			t[size];

	total = 0;
	while (++i < size)
	{
		t[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(t, size, 0, 0);
	i = 0;
	while (t[i] != r->a.LNBR)
		++i;
//	ft_printf("t[%d] = %d\n", i, t[i]);//////////////////////////////////////////
	while (++j < size)
	{
		i + j == size ? i = -j : 0;
//		ft_printf("t[%2d] = %10d\tr->a.LNBR = %10d\n", i+j, t[i+j], r->a.LNBR);//
		t[i + j] == r->a.LNBR ? ++total : 0;
		t[i + j] == r->a.LNBR ? r->a.low->bd |= GOOD : 0;
		rotate(NULL, &r->a, 0);
	}
//	ft_printf("total = %d size = %d\n", total, size);////////////////////////////
	total == size ? r->bd |= GOOD : 0;
//	ft_printf("{black}{bold}END\tERROR VERIF{eoc}\n\n");/////////////////////////
}

void			push_swap(t_roll *r, char **p, int size)
{
	ft_printf("{yellow}{bold}{underline}IN\tPUSH SWAP{eoc}\n");//////////////////
	t_tab		t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
//	ft_printf("{yellow}{bold}{underline}WHILE{eoc}\n");//////////////////////////
	while (check_sort(&r->a, r->nb_a, -1))
		if (go_to_best_rotation(r, r->nb_a, -1))
			break ;
//	ft_printf("{red}{bold}{underline}END WHILE{eoc}\n\n");///////////////////////
	int test = 0;
	while (!(r->bd & GOOD))
	{
		go_to_last_value(r, r->nb_a);
		error_verif(r, r->nb_a, -1, -1);
		if (++test == 42)
		{
			ft_printf("grosse merde!!\n");
			break ;
		}
		ft_printf("{blue}{underline}{bold}END BOUCLE{eoc}\n");///////////////////
		ft_printf("-------------------------------------------------\n\n\n");////
	}
//	while (r->nb_b)
//	{
//		go_to_start_of_end(r);

//	}
	ft_printf("{red}{bold}{underline}\t\t--- END BEST ROT ---{eoc}\n\n");////////
	ft_printf("{yellow}{bold}{underline}END\tPUSH SWAP{eoc}\n");/////////////////
//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
}
