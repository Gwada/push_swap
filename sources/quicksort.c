/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:04:12 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/17 20:36:48 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_swap(t_tab *a, t_tab *b)
{
	int			tmp;

	tmp = (int)a->n;
	a->n = b->n;
	b->n = tmp;
}

void			ft_qsort(t_tab *t, int size, int i, int j)
{
	int			pvt;

	if (size < 2)
		return ;
	pvt = size / 2;
	i = (pvt == 0) ? 1 : 0;
	j = (pvt == size - 1) ? size - 2 : size - 1;
	while (i <= j)
	{
		if (t[i].n <= t[pvt].n)
		{
			if (i > pvt)
			{
				ps_swap(t + i, t + pvt);
				pvt = i;
			}
			i += (i + 1 == pvt) ? 2 : 1;
		}
		else
		{
			ps_swap(t + i, t + j);
			if (j < pvt)
			{
				ps_swap(t + j, t + pvt);
				pvt = j;
			}
			j -= (j - 1 == pvt) ? 2 : 1;
		}
	}
	ft_qsort(t, pvt, 0, 0);
	ft_qsort(t + pvt + 1, size - pvt - 1, 0, 0);
}
