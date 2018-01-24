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
	ft_printf("\n{black}{bold}IN chek{eoc}\n");//
	t_pile		*tmp;

	tmp = r->a.low ? &r->a : NULL;
	tmp ? r->bd |= GOOD : 0;
	display_pile(tmp, 'A');//
	while (++i < r->size)
	{
		ft_printf("%d\t%d\n", (int)t[i].n, tmp->low->nbr);//
		(int)t[i].n != tmp->low->nbr ? r->bd &= ~GOOD : 0;
		tmp = tmp->low;
	}
	ft_printf("{black}{bold}end check{eoc}\n\n");//
}

static	void	dlavaury_sort(t_tab *t, t_roll *r)
{
	ft_printf("{black}{bold}IN DLAVAURY{eoc}\n\n");//
	while (!(r->bd & GOOD))
	{
		display_pile(&r->a, 'A');//
		if (r->a.low->bd & R_ROT)
		{//
			ft_printf("test1\n");//
			r_rotate(t, &r->a);
		}//
		else if (r->a.low->bd & ROT)
		{//
			ft_printf("test2\n");//
			r_rotate(t, &r->a);
		}//
		display_pile(&r->a, 'A');//
		check_sort(t, r, -1);
		display_pile(&r->a, 'A');//
	}
	r->bd & GOOD ? ft_printf("le tri est fini!!\n") : 0;//
	ft_printf("{black}{bold}END DLAVAURY{eoc}\n\n");//
}

void		push_swap(t_roll *r, char **p, int size)
{
	t_tab	t[size];

	ft_printf("{yellow}{bold}IN PUSH SWAP{eoc}\n\n");
	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	display_piles(&r->a, &r->b);
	crack_that_shit(t, r, 0);
	dlavaury_sort(t, r);


/*affichage de debeugage*/
//	int i = -1;
//	while (++i < size)//
//	{//
//		ft_printf("%-2d) t[%2d]\tn = {green}[%2d]{eoc}\t",i + 1, i, t[i].n);//
//		ft_printf("m.nbr = {red}[%2d]{eoc}", t[i].m.nbr);//
//		ft_printf("\tm.pos = %2d", i, t[i].m.pos);//
//		t[i].m.bd & MAX ? ft_printf("\tMAX") : 0;//
//		t[i].m.bd & MIN ? ft_printf("\tMIN") : 0;//
//		ft_printf("\n");//
//	}//
	ft_printf("{yellow}{bold}END PUSH SWAP{eoc}\n\n");
}
