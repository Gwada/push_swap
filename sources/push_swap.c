/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/19 20:17:46 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_roll *r, char **p, int size)
{
	t_tab	t[size];

	ft_printf("{yellow}{bold}IN PUSH SWAP{eoc}\n\n");
	init_tab(t, r, p, -1);
	if (r->bd & ERR)
		return ;
	init_sort(t, r, -1);
	int i = -1;
	while (!(r->bd & GOOD) && ++i < size)//////////
	{///////////
		ft_printf("%d)t[%d]\tn = {green}[%d]{eoc}\t",i + 1, i, t[i].n);///////////////
		ft_printf("\tm.nbr = {red}[%d]{eoc}", t[i].m.nbr);//////////////
		ft_printf(" m.pos = %d", i, t[i].m.pos);//////////////
		t[i].m.bd & MAX ? ft_printf("\tMAX") : 0;////////////////
		t[i].m.bd & MIN ? ft_printf("\tMIN") : 0;/////////////////
		ft_printf("\n");////////////////////
	}//////////////////
	r->bd & GOOD ? ft_printf("{green}{underline}{bold}GOOD END (entree triee){eoc} / ") : 0;///////////
	ft_printf("{yellow}{bold}END PUSH SWAP{eoc}\n\n");
}
