/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:17:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/17 19:47:40 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	display_error(t_roll *r)
{
	r->bd |= ERR;
	ft_dprintf(2, "Error\n");
	//ft_printf("r->size = %d\n", r->size);//
}

int				main(int argc, char **argv)
{
	t_roll		r;

	if (argc > 1)
	{
		//if (!((r.size = init_struct(&r, ++argv, 0))))
			//return (display_error(&r));
		r.size = init_struct(&r, ++argv, 0);
		ft_printf("r.size = %d\n", r.size);//
		!(r.bd & ERR) && r.size ? push_swap(&r, argv, r.size) : 0;
	}
	argc == 1 ? ft_printf("no argument end\n") : 0;//
	r.bd & ERR ? display_error(&r) : ft_printf("OK\n");//
	return (0);
}
