/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:30:29 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/30 20:19:52 by dlavaury         ###   ########.fr       */
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
	if (!(ft_strcmp(s, "sa\n")))
		return (swap(r, &r->a, 'a'));
	else if (!(ft_strcmp(s, "sb\n")))
		return (swap(r, &r->b, 'b'));
	else if (!(ft_strcmp(s, "ss\n")))
		return (s_swap(r));
	else if (!(ft_strcmp(s, "ra\n")))
		return (rotate(r, &r->a, 'a'));
	else if (!(ft_strcmp(s, "rb\n")))
		return (rotate(r, &r->b, 'b'));
	else if (!(ft_strcmp(s, "rra\n")))
		return (r_rotate(r, &r->a, 'a'));
	else if (!(ft_strcmp(s, "rrb\n")))
		return (r_rotate(r, &r->b, 'b'));
	else if (!(ft_strcmp(s, "rr\n")))
		return (d_rotate(r, ROT));
	else if (!(ft_strcmp(s, "rrr\n")))
		return (d_rotate(r, R_ROT));
	else if (!(ft_strcmp(s, "pa\n")))
		return (simple_push(r, &r->b, &r->a, 'a'));
	else if (!(ft_strcmp(s, "pb\n")))
		return (simple_push(r, &r->a, &r->b, 'b'));
	else
		ft_dprintf(2, "Error\n");
	r->bd |= ERR;
}

static	void	checker(t_roll *r, char **p, int size)
{
	char	*s;
	t_tab	t[size];

	init_tab(t, r, p, -1);
	s = NULL;
	if (r->bd & ERR || r->bd & GOOD)
	{
		r->bd & ERR ? ft_dprintf(2, "ERROR\n") : 0;
		return ;
	}
	while (r->bd ^ ERR && get_next_line(0, &s))
	{
		//s ? ft_printf("%s\n", s) : 0;
		check_that(r, s);
		s ? free(s) : 0;
	}
	r->bd & ERR ? ft_dprintf(2, "Error\n") : 0;
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
		!(r.bd & ERR) && r.size ? checker(&r, argv, r.size) : 0;
	}
	r.bd & ERR ? display_error(&r) : 0;//
	return (0);
}
