/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:23:15 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/30 19:33:15 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static	int		again(t_roll *r, int i)
{
	int			ret;

	ret = 0;
	while (++i < r->nb_a)
	{
		ALBD & NO_CHECK ? ++ret : 0;
		rotate(NULL, &r->a, 0);
	}
	return (ret);
}

static	void	push_swap_q_sort(t_roll *r, int min, int max, int size)
{
	ft_printf("{bold}{red}IN\tQ_SORT\tmin = %d max = %d\n{eoc}", min, max);
	int			i;
	int			j;
	int			t[size];

	if (size <= 25)
		return ;
	i = -1;
	j = 0;
	if (min == max)
			return ;
	while (++i < r->nb_a)
	{
		if (ALBD ^ GOOD)
			ALNBR >= min && ALNBR <= max ? t[j++] = ALNBR : 0;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(t, j, 0, 0);
	i = -1;
	while (++i < r->nb_a)
	{
		ALBD ^ GOOD && ALNBR <= t[j / 2] ? ALBD = NO_CHECK : 0;
		rotate(NULL, &r->a, 0);
	}
	while (again(r, -1))
	{
		if (ALBD & NO_CHECK)
		{
			ALBD = PUSH;
			simple_push(r, &r->a, &r->b, 'b');
		}
		else
			rotate(r, &r->a, 'a');
	}
//	while (r->nb_b && !(BLBD = 0))
//		simple_push(r, &r->b, &r->a, 'a');
	push_swap_q_sort(r, t[j / 2], t[j - 1], j / 2);
//	push_swap_q_sort(r, t[j / 2], t[j - 1], j / 2);
//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
}*/

void		push_swap(t_roll *r, char **p, int size)
{
	t_tab	t[size];

	init_tab(t, r, p, -1);
	if (r->bd & ERR || r->bd & GOOD)
		return ;
	r->bd &= ~COLOR;
	r->bd &= ~VISUAL;
//	int i = -1, test = 0;
//	r->size > 200 ? push_swap_q_sort(r, r->a_min, r->a_max, r->size) : 0;
//	while (r->nb_b && !(BLBD = 0))
//		simple_push(r, &r->b, &r->a, 'a');

	find_best_rot(r, t, 0, -1);
	first_step(r, t, -1, 0);
//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
	second_step(r, t, -1);
	last_step(r, -1);




//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////

//	i = -1, test = 0;
//	while (++i < r->size)
//	{
//				ft_printf("{bold}{green}t[%3d].n = %11ld\t{eoc}", i, t[i].n);
//				ft_printf("{bold}ALNBR = %11d\t{eoc}", ALNBR);
//				ALBD & GOOD ? ft_printf("{green}{bold}ALBD & GOOD{eoc}\t") : 0;
//				(int)t[i].n == ALNBR ? ft_printf("{green}{bold}GOOD{eoc}\n") : ft_printf("{red}{bold}ERROR !!!{eoc}\n");
//		(int)t[i].n != ALNBR ? ++test : 0;
//		rotate(NULL, &r->a, 0);
//	}
//	display_piles(r, &r->a, &r->b);//////////////////////////////////////////////
//	ft_printf("{bold}{yellow}size = %d\tr->dep = %d r->pvt = %d\t{eoc}", r->size, r->dep, r->pvt);///
//	test ? ft_printf("{red}{bold}{underline}error!!{eoc}\n") : 0;////////////////
//	!test ? ft_printf("{green}{bold}{underline}TRI OK!!{eoc}\n") : 0;////////////
}
