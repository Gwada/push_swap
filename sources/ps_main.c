/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:17:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/16 22:14:17 by dlavaury         ###   ########.fr       */
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
		if (!(init_main(&r, ++argv, 1)))
			return (display_error(&r));
	//	ft_printf("main -> end init\n");//
	}
	argc == 1 ? ft_printf("no argument end\n") : 0;//
	ft_printf("---------------------------------------------");//
	ft_printf("OK\n");//
	return (0);
}
