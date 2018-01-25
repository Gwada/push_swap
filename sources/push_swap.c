/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/20 20:13:38 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	check_sort(t_tab *t, t_roll *r, int i)
{
//	ft_printf("\n{black}{bold}IN chek{eoc}\n");//
	t_pile		*tmp;

	tmp = r->a.low ? &r->a : NULL;
//	display_pile(tmp, '1');//
	while (++i < r->size)
	{
//		ft_printf("%d\t%d\n", (int)t[i].n, tmp->low->nbr);//
//		tmp->low->bd & R_ROT ? ft_printf("rrot\n") : 0;
		if ((int)t[i].n != tmp->low->nbr)
			break ;
		tmp = tmp->low;
	}
	i == r->size ? r->bd |= GOOD : 0;
//	ft_printf("{black}{bold}end check{eoc}\n\n");//
}

void		push_swap(t_roll *r, char **p, int size)
{
	t_tab	t[size];

//	ft_printf("{yellow}{bold}{underline}IN PUSH SWAP{eoc}\n\n");
	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	crack_that_shit(t, r, 0);
	while (!(r->bd & GOOD))
	{
		if (r->a.low->bd & R_ROT)
		{//
			r->a.low->bd &= ~R_ROT;
			r_rotate(r, t, &r->a, 'a');
		}//
		else if (r->a.low->bd & ROT)
		{//
			r->a.low->bd &= ~ROT;

			rotate(r, t, &r->a, 'a');
		}//
		check_sort(t, r, -1);
	}
//	r->bd & GOOD ? ft_printf("le tri est fini!!\n") : 0;//

//	ft_printf("{yellow}{bold}{underline}END PUSH SWAP{eoc}\n\n");
}
