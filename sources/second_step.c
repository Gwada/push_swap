/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:25:54 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/01 19:57:42 by dlavaury         ###   ########.fr       */
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

/*static	int		right_check(t_roll *r, int min, int max)
{
	while (ALLLBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	max = ALLLNBR;
	while (ALLBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	if ((ALNBR > min && ALNBR < max)
	|| (min > max && (ALNBR > min || ALNBR < max)))
	{
		swap(r, &r->a, 'a');
		return (1);
	}
	return (0);
}

static	int		left_check(t_roll *r, int min, int max)
{
	while (ATTBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	min = ATTNBR;
	while (ATBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	if ((ALNBR > min && ALNBR < max)
	|| (min > max && (ALNBR > min || ALNBR < max)))
	{
		r_rotate(r, &r->a, 'a', GOOD);
		swap(r, &r->a, 'a');
		return (1);
	}
	return (0);
}

static	void	fixe_that(t_roll *r)
{
	if (ALLBD & GOOD && right_check(r, ALLNBR, 0))
		return ;
	if (ATBD & GOOD && left_check(r, 0, ATNBR))
		return ;
	r->b_rot < 1 ? push(r, &r->a, &r->b, 'b') : 0;
}*/

void			second_step(t_roll *r, t_tab *t, int i)
{
//	int test = 0;//
	while (++i < 9)
	{
		fixe_push(r, t, i);
		while (error_checker(r)/* && r->dep < 3073*/)
			nearest_rotation(r, NO_CHECK, r->nb_a, 0);
//		return ;
	}
}
