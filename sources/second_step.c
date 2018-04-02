/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:25:54 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/02 15:41:34 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		error_checker(t_roll *r)
{
	int			i;
	int			total;

	i = -1;
	total = 0;
	while (++i < r->nb_a)
	{
		ALBD & NO_CHECK ? ++total : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	return (total);
}

void			second_step(t_roll *r, t_tab *t, int i)
{
	while (++i < 9)
	{
		fixe_push(r, t, i);
		while (error_checker(r))
			nearest_rotation(r, r->nb_a, 0);
	}
}
