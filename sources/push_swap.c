/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/18 21:48:15 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_roll *r, char **p, int size)
{
	t_tab	t[size];

	ft_printf("\nin push_swap\n");
	init_tab(t, r, p, -1);
	if (r->bd & ERR)
		return ;
	init_sort(t, r, -1);
	int i = -1;
	while (!(r->bd & GOOD) && ++i < size)
	{
		ft_printf("%d\tt[%d].n = [%d]\t",i + 1, i, t[i].n);
		ft_printf("\tt[%d].m.nbr = [%d]\n", i, t[i].m.nbr);
	}
//	(void)t;
//	(void)r;
//	(void)p;
//	(void)size;
//	ft_printf("in ps\n");
	ft_printf("end push_swap\n\n");
}
