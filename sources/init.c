/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:58:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/17 20:59:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		parse_nbr(t_roll *r, char *n, int *size)
{
	!CHR("-+0123456789", *n) ? r->bd |= ERR : 0;
	while (*n && !(r->bd & ERR))
	{
		!CHR("-+cv 0123456789", *n) ? r->bd |= ERR : 0;
		*n == 'c' && r->bd & COLOR ? r->bd |= ERR : 0;
		*n == 'c' && !ft_strchr(" v", n[1]) ? r->bd |= ERR : 0;
		*n == 'v' && r->bd & VISUAL ? r->bd |= ERR : 0;
		*n == 'v' && !CHR(" c", n[1]) ? r->bd |= ERR : 0;
		CHR("cv", *n) && *size ? r->bd |= ERR : 0;
		*n == '-' && !CHR("cv0123456789", n[1]) ? r->bd |= ERR : 0;
		!(r->bd & COLOR) && *n == 'c' ? r->bd |= COLOR : 0;
		!(r->bd & VISUAL) && *n == 'v' ? r->bd |= VISUAL : 0;
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
	r->bd = 0;
	r->size = 0;
	r->nb_ea = 0;
	r->nb_eb = 0;
	r->a.nbr = 0;
	r->a.root = &r->a;
	r->a.top = &r->a;
	r->a.low = &r->a;
	r->b.root = &r->b;
	r->b.top = &r->b;
	r->b.low = &r->b;
	r->b.nbr = 0;
	while (*nbr && !(r->bd & ERR))
	{
		parse_nbr(r, *nbr++, &size);
		r->bd & STRING && *nbr && size ? r->bd |= ERR : 0;
	}
	return (r->bd & ERR ? 0 : size);
}

void			init_tab(t_tab *t, t_roll *r, char **a, int i)
{
	while (*a)
	{
		while ((r->bd & ERR && **a))
		{
			ft_strchr("+0123456789", **a) ? r->bd &= ~ERR : 0;
			**a == '-' && ft_strchr(ISNUM, *a[1]) ? r->bd &= ~ERR : 0;
			r->bd & ERR ? ++(*a) : 0;
		}
		if (!(r->bd & ERR))
		{
			**a == '+' || (**a == '-' && (r->bd |= MIN)) ? ++(*a) : 0;
			t[++i].n = 0;
			while (**a && **a >= '0' && **a <= '9')
			{
				t[i].n = t[i].n * 10 + *((*a)++) - '0';
				if (((t[i].n > IMAX && !(r->bd & MIN)) || (t[i].n > -IMIN && r->bd & MIN)) && (r->bd |= ERR))
					return ;
			}
			r->bd & MIN ? t[i].n = -t[i].n : 0;
			t[i].m.nbr = (int)t[i].n;
			r->bd & MIN ? r->bd &= ~MIN : 0;
		}
		++a;
	}
}

void			init_sort(t_tab *t, t_roll *r, int i)
{
	ft_printf("in init sort\n\n");
	ft_qsort(t, r->size, 0, 0);
	while (!(r->bd & ERR) && ++i < r->size - 1)
		t[i].n == t[i + 1].n ? r->bd |= ERR : 0;
	r->bd & ERR ? ft_printf("t[%d].n = %d t[%d].n = %d\n", i, t[i].n, i+1, t[i+1].n) : 0;
	ft_printf("end init sort\n\n");
}
