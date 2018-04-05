/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:30:29 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/04 23:51:39 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		display_error(t_roll *r)
{
	r->bd |= ERR;
	ft_dprintf(2, "Error\n");
	return (0);
}

static	void	check_that(t_roll *r, char *s)
{
	if (!(ft_strcmp(s, "sa")))
		return (swap(r, &r->a, 'a'));
	else if (!(ft_strcmp(s, "sb")))
		return (swap(r, &r->b, 'b'));
	else if (!(ft_strcmp(s, "ss")))
		return (s_swap(r));
	else if (!(ft_strcmp(s, "ra")))
		return (rotate(r, &r->a, 'a', 0));
	else if (!(ft_strcmp(s, "rb")))
		return (rotate(r, &r->b, 'b', 0));
	else if (!(ft_strcmp(s, "rra")))
		return (r_rotate(r, &r->a, 'a', 0));
	else if (!(ft_strcmp(s, "rrb")))
		return (r_rotate(r, &r->b, 'b', 0));
	else if (!(ft_strcmp(s, "rr")))
		return (d_rotate(r, ROT));
	else if (!(ft_strcmp(s, "rrr")))
		return (d_rotate(r, R_ROT));
	else if (!(ft_strcmp(s, "pa")))
		return (simple_push(r, &r->b, &r->a, 'a'));
	else if (!(ft_strcmp(s, "pb")))
		return (simple_push(r, &r->a, &r->b, 'b'));
	r->bd |= ERR;
}

static	void	end_checker(t_roll *r, t_tab *t, int result, int i)
{
	while (++i < r->size)
	{
		(int)t[i].n != ALNBR ? ++result : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	if (r->bd & COLOR)
	{
		if (result)
			ft_printf("{red}{bold}{underline}KO\n{eoc}");
		else
			ft_printf("{green}{bold}{underline}OK\n{eoc}");
	}
	else
		ft_printf("%s\n", result ? "KO" : "OK");
}

static	void	checker(t_roll *r, char **p, int size)
{
	char	*s;
	t_tab	t[size];

	init_tab(t, r, p, -1);
	s = NULL;
	if (r->bd & ERR)
		return ;
	!(r->bd & COLOR) && !(r->bd & VISUAL) ? r->bd = 0 : 0;
	while (get_next_line(0, &s))
	{
		s && *s ? check_that(r, s) : 0;
		s ? free(s) : 0;
		if (r->bd & ERR)
			break ;
	}
	if (r->bd & ERR)
		return ;
	else
		end_checker(r, t, 0, -1);
}

int				main(int argc, char **argv)
{
	t_roll		r;

	if (argc > 1)
	{
		if (!(r.size = init_struct(&r, ++argv, 0)))
			return (display_error(&r));
		while (r.bd & ERR && *argv)
		{
			while (r.bd & ERR && **argv)
			{
				CHR("+0123456789", **argv) ? r.bd &= ~ERR : 0;
				**argv == '-' && CHR(ISNUM, (*argv)[1]) ? r.bd &= ~ERR : 0;
				r.bd & ERR ? ++(*argv) : 0;
			}
			r.bd & ERR && !**argv ? ++argv : 0;
		}
		!(r.bd & ERR) && r.size > 0 ? checker(&r, argv, r.size) : 0;
	}
	r.bd & ERR ? display_error(&r) : 0;
	return (0);
}
