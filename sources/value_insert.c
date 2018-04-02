/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:55:43 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/02 15:08:33 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			value_insert(t_roll *r, int *rt, int min, int max)
{
	int		i;
	int		test;

	i = -1;
	test = 0;
	while (++i < r->nb_b)
	{
		if (!test)
		{
			if (rt && ((min < BLNBR && BLNBR < max)
			|| (min > max && (min < BLNBR || BLNBR < max))))
			{
				test = 1;
				*rt = i;
			}
			else if ((min < BLNBR && BLNBR < max)
			|| (min > max && (min < BLNBR || BLNBR < max)))
				test = 1;
		}
		rotate(NULL, &r->b, 0, 0);
	}
	return (test);
}
