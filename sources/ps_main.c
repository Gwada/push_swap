/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:17:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/06 16:19:57 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		display_error(t_roll *r)
{
	r->bd |= ERR;
	ft_dprintf(2, "Error\n");
	return (0);
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
		r.bd ^ ERR && r.size > 0 ? push_swap(&r, argv, r.size) : 0;
	}
	r.bd & ERR ? display_error(&r) : 0;
	return (0);
}
