/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/25 20:36:28 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	check_sort(t_tab *t, t_roll *r, int i)
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
}

void		push_swap(t_roll *r, char **p, int size)
{
	t_tab	t[size];
//	ft_printf("{yellow}{bold}{underline}IN PUSH SWAP{eoc}\n\n");//

	init_tab(t, r, p, -1);
//	display_piles(r, &r->a, &r->b);//
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	crack_that_shit(t, r, 0, 0);
	int i = 0;
//	display_piles(r, &r->a, &r->b);//
	while (!(r->bd & GOOD))
	{
//		ft_printf("r->a.low->nbr = %d ", r->a.low->nbr);
//		r->a.low->bd & GOOD ? ft_printf("GOOD ") : 0;
//		r->a.low->bd & SWAP ? ft_printf("SWAP ") : 0;
//		r->a.low->bd & PUSH ? ft_printf("PUSH ") : 0;
//		r->a.low->bd & R_ROT ? ft_printf("R_ROT ") : 0;
//		r->a.low->bd & ROT ? ft_printf("ROT ") : 0;
//		ft_printf("\n");

		/*if (r->a.low->bd & GOOD)
		{//
			r->a.low->bd &= ~GOOD;
			r_rotate(r, t, &r->a, 'a');
		}//*/

		if (r->a.low->bd & SWAP)
		{
			r->a.low->bd &= ~SWAP;
			swap(r, &r->a, 'a');
			r_rotate(r, t, &r->a, 'a');
			r->a.low->bd |= R_ROT;
		}
		else if (r->a.low->bd & PUSH)
		{
			r->a.low->bd &= ~PUSH;
			push(r, &r->a, &r->b);
		}

		else if (r->a.low->bd & R_ROT)
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
		if (++i == 20 || r->bd & GOOD)
			break ;
	//	crack_that_shit(t, r, 0, 0);
	}
	i == 20 ? ft_printf("tu fais de la merde\n") : 0;
	r->bd & GOOD ? ft_printf("le tri est fini!!\n") : 0;//

//	ft_printf("{yellow}{bold}{underline}END PUSH SWAP{eoc}\n\n");
}
