/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:58:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/01 19:36:19 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	parse_nbr(t_roll *r, char *n, int *size)
{
	!CHR("-+0123456789", *n) ? r->bd |= ERR : 0;
	while (*n && r->bd ^ ERR)
	{
		!CHR("-+cv 0123456789", *n) ? r->bd |= ERR : 0;
		*n == 'c' && r->bd & COLOR ? r->bd |= ERR : 0;
		*n == 'c' && !ft_strchr(" v", n[1]) ? r->bd |= ERR : 0;
		*n == 'v' && r->bd & VISUAL ? r->bd |= ERR : 0;
		*n == 'v' && !CHR(" c", n[1]) ? r->bd |= ERR : 0;
		CHR("cv", *n) && *size ? r->bd |= ERR : 0;
		*n == '-' && !CHR("cv0123456789", n[1]) ? r->bd |= ERR : 0;
		r->bd ^ COLOR && *n == 'c' ? r->bd |= COLOR : 0;
		r->bd ^ VISUAL && *n == 'v' ? r->bd |= VISUAL : 0;
		*n == '+' && !CHR(ISNUM, n[1]) ? r->bd |= ERR : 0;
		CHR("+-", *n) && !n[1] ? r->bd |= ERR : 0;
		*n == ' ' ? r->bd |= STRING : 0;
		*n == ' ' && !CHR("-+0123456789", n[1]) ? r->bd |= ERR : 0;
		*n == ' ' && !n[1] ? r->bd |= ERR : 0;
		CHR(ISNUM, *n) && (!n[1] || n[1] == ' ') ? ++*size : 0;
		CHR(ISNUM, *n) && !CHR("0123456789 ", n[1]) ? r->bd |= ERR : 0;
		++n;
	}
}

int				init_struct(t_roll *r, char **nbr, int size)
{
	ft_bzero(r, sizeof(*r));
	r->a.root = &r->a;
	r->a.top = r->a.low;
	r->a.low = r->a.top;
	r->b.root = &r->b;
	r->b.top = r->b.low;
	r->b.low = r->b.top;
	while (*nbr && r->bd ^ ERR)//
	{
		parse_nbr(r, *nbr++, &size);
		r->bd & STRING && *nbr && size ? r->bd |= ERR : 0;
	}
	if (r->bd & ERR)
		return (0);
	r->bd |= ERR;
	return (size);
}

static	void	init_sort(t_tab *t, t_roll *r, int i)
{
	ft_ps_qsort(t, r->size, 0, 0);
	r->min = (int)t[0].n;
	r->max = (int)t[r->size - 1].n;
	r->nb_a = r->size;
	r->nb_b = 0;
	r->dep = 0;
	r->pvt = (int)t[r->size / 2].n;
	r->a_max = (int)t[r->size - 1].n;
	r->a_min = (int)(*t).n;
	r->bd |= GOOD;
	while (r->bd ^ ERR && ++i < r->size)
	{
		i < r->size - 1 && t[i].n == t[i + 1].n ? r->bd |= ERR : 0;
		t[i].n != t[i].m.nbr ? r->bd &= ~GOOD : 0;
		t[i].n == t[i].m.nbr ? ++r->cor : 0;
		t[i].m.low = &r->a;
		t[i].m.top = r->a.top ? r->a.top : &r->a;
		if (r->a.low)
			r->a.top->low = &t[i].m;
		else 
			r->a.low = &t[i].m;
		r->a.top = &t[i].m;
	}
}

void			init_tab(t_tab *t, t_roll *r, char **a, int i)
{
	while (*a && ++i < r->size)
	{
		ft_bzero(&t[i], sizeof(*t));
		while (**a)
		{
			CHR("+ ", **a) || (**a == '-' && (r->bd |= MINUS)) ? ++(*a) : 0;
			while (**a && **a >= '0' && **a <= '9')
			{
				t[i].n = t[i].n * 10 + *((*a)++) - '0';
				if (((t[i].n > IMAX && r->bd ^ MINUS)
				|| (t[i].n > -IMIN && r->bd & MINUS)) && (r->bd |= ERR))
					return ;
			}
			r->bd & MINUS ? t[i].n = -t[i].n : 0;
			t[i].m.nbr = (int)t[i].n;
			r->bd & MINUS ? r->bd &= ~MINUS : 0;
			if (**a == ' ')
				break ;
		}
		**a != ' ' ? ++a : 0;
	}
	r->bd ^ ERR ? init_sort(t, r, -1) : 0;
}
