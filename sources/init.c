/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:58:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/20 20:13:41 by dlavaury         ###   ########.fr       */
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
	ft_bzero(r, sizeof(*r));
	r->a.root = &r->a;
	r->a.top = r->a.low;
	r->a.low = r->a.top;
	r->b.root = &r->b;
	r->b.top = r->b.low;
	r->b.low = r->b.top;
	while (*nbr && !(r->bd & ERR))
	{
		parse_nbr(r, *nbr++, &size);
		r->bd & STRING && *nbr && size ? r->bd |= ERR : 0;
	}
	if (r->bd & ERR)
		return (0);
	r->bd |= ERR;
	return (size);
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
				if (t[i].n > IMAX && !(r->bd & MINUS)  && (r->bd |= ERR))
					return ;
				if (t[i].n > -IMIN && r->bd & MINUS && (r->bd |= ERR))
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
	!(r->bd & ERR) ? init_sort(t, r, -1) : 0;
}

void			init_sort(t_tab *t, t_roll *r, int i)
{
	ft_printf("{magenta}{bold}IN INIT SORT{eoc}\n");//
	ft_qsort(t, r->size, 0, 0);
	r->nb_a = (unsigned)r->size;
	r->a_max = (int)t[r->size - 1].n;
	r->a_min = (int)(*t).n;
	r->bd |= GOOD;
	while (!(r->bd & ERR) && ++i < r->size)
	{
		(i < r->size - 1) && (t[i].n == t[i + 1].n) ? r->bd |= ERR : 0;
		t[i].n != t[i].m.nbr ? (r->bd &= ~GOOD) : (t[i].m.bd |= GOOD);
		t[i].n == t[i].m.nbr ? ++r->cor : 0;
		t[i].m.nbr == r->a_max ? t[i].m.bd |= MAX : 0;
		t[i].m.nbr == r->a_min ? t[i].m.bd |= MIN : 0;
		t[i].m.pos = i;
		t[i].m.low = &r->a;
		t[i].m.top = r->a.top ? r->a.top : &r->a;
		r->a.low ? (r->a.top->low = &t[i].m) : (r->a.low = &t[i].m);
		r->a.top = &t[i].m;
	}
//	display_piles(r->a.low, r->b.low);//////////////
	//ft_printf("r.size = %d\n\n", r->size);//
//	ft_printf("{green}{underline}Pile A\t\tPileB{eoc}\n");//
//	ft_printf("r.a_max\t= %2d\tr.b_max\t= %2d\n", r->a_max, r->b_max);//
//	ft_printf("r.a_min\t= %2d\tr.b_min\t= %2d\n", r->a_min, r->b_min);//
//	ft_printf("r.nb_a\t= %2d\tr.nb_b\t= %2d\n", r->nb_a, r->nb_b);//
//	ft_printf("{magenta}{bold}END INIT SORT{eoc}\n\n");//
//	while (!(r->bd & GOOD))//
//	{//
//	find_best(t, r, 0);
//	}//
	ft_printf("{magenta}{bold}END INIT SORT{eoc}\n\n");//
}
