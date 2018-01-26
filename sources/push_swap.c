/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/26 21:26:38 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static	void	check_sort(t_tab *t, t_roll *r, int i)
{
//	ft_printf("\n{black}{bold}IN chek{eoc}\n");//
	t_pile		*tmp;

	tmp = r->a.low ? r->a.low : NULL;
//	display_pile(tmp, '1');//
	while (++i < r->size)
	{
//		ft_printf("%d\t%d\n", (int)t[i].n, tmp->low->nbr);//
//		tmp->low->bd & R_ROT ? ft_printf("rrot\n") : 0;
		if ((int)t[i].n != tmp->nbr)
			break ;
		tmp = tmp->low;
	}
	i == r->size ? r->bd |= GOOD : 0;
//	ft_printf("{black}{bold}end check{eoc}\n\n");//
}*/

void		push_swap(t_roll *r, char **p, int size)
{
	ft_printf("{yellow}{bold}{underline}IN PUSH SWAP{eoc}\n");//////////////////
	t_tab	t[size];

	init_tab(t, r, p, -1);
	display_piles(r, &r->a, &r->b);/////////////////////////
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	find_best_combinaison(t, r, 0);
	ft_printf("r->cor = %d\tr->b_rot = %d\n", r->cor, r->b_rot);////////////////
	crack_that_shit(t, r);
	display_piles(r, &r->a, &r->b);/////////////////////////
	int i = -1;
	while (++i < r->size)
	{
		r->a.low->bd & ROT ? ft_printf("{green}ROT {eoc}", r->a.low->nbr) : 0;
		r->a.low->bd & R_ROT ? ft_printf("{red}R_ROT {eoc}", r->a.low->nbr) : 0;
		ft_printf("%d ", r->a.low->nbr);
		rotate(NULL, NULL, &r->a, 0);
	}
	ft_printf("\n");

/*	while (!(r->bd & GOOD))
	{
//		ft_printf("r->a.low->nbr = %d ", r->a.low->nbr);
//		r->a.low->bd & GOOD ? ft_printf("GOOD ") : 0;
//		r->a.low->bd & SWAP ? ft_printf("SWAP ") : 0;
//		r->a.low->bd & PUSH ? ft_printf("PUSH ") : 0;
//		r->a.low->bd & R_ROT ? ft_printf("R_ROT ") : 0;
//		r->a.low->bd & ROT ? ft_printf("ROT ") : 0;
//		ft_printf("\n");

		check_sort(t, r, -1);
		if (++i == 200 || r->bd & GOOD)
			break ;
	//	crack_that_shit(t, r, 0, 0);
	}
	i == 20 ? ft_printf("tu fais de la merde\n") : 0;*/
	r->bd & GOOD ? ft_printf("le tri est fini!!\n") : 0;//

	ft_printf("{yellow}{bold}{underline}END PUSH SWAP{eoc}\n");
}
