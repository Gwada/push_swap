/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:58:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/16 22:14:13 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		parse_nbr(t_roll *r, char *nbr, int num)
{
	num = 0;
	//ft_printf("\nin parse_nbr\n");//
	!ft_strchr("-+0123456789", *nbr) ? r->bd |= ERR : 0;
	while (*nbr && !(r->bd & ERR))
	{
		// verif validite caractere
		!ft_strchr("-+cv 0123456789", *nbr) ? r->bd |= ERR : 0;

		// verif presence flags bonus
		*nbr == 'c' && r->bd & COLOR ? r->bd |= ERR : 0;
		*nbr == 'c' && !ft_strchr(" v", nbr[1]) ? r->bd |= ERR : 0;
		*nbr == 'v' && r->bd & VISUAL ? r->bd |= ERR : 0;
		*nbr == 'v' && !ft_strchr(" c", nbr[1]) ? r->bd |= ERR : 0;
		ft_strchr("cv", *nbr) && r->size ? r->bd |= ERR : 0;

		// acquisition flags
		*nbr == '-' && !ft_strchr("cv0123456789", nbr[1]) ? r->bd |= ERR : 0;
		!(r->bd & COLOR) && *nbr == 'c' ? r->bd |= COLOR : 0;
		!(r->bd & VISUAL) && *nbr == 'v' ? r->bd |= VISUAL : 0;
		*nbr == '+' && !ft_strchr("0123456789", nbr[1]) ? r->bd |= ERR : 0;
		*nbr == ' ' && r->size ? r->bd |= ERR : 0;
		ft_strchr("+-", *nbr) && !nbr[1] ? r->bd |= ERR : 0;
		//*nbr == ' ' && r->size ? ft_printf("il y a une erreur ici!!\n") : 0;
		*nbr == ' ' ? r->bd |= STRING : 0;
		*nbr == ' ' && !ft_strchr("-+0123456789", nbr[1]) ? r->bd |= ERR : 0;
		*nbr == ' ' && !nbr[1] ? r->bd |= ERR : 0;
		ft_printf("|%c| ", *nbr++);//
		//r->bd & MINUS ? ft_printf("minus\n") : ft_printf("no minus\n");//
		//++nbr;//
	}
	//r->bd & ERR ? ft_printf("error!!!\n") : 0;//
	ft_printf("\n");
}

int				init_main(t_roll *r, char **nbr, int size)
{
	(void)size;
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
		ft_printf("test |%s|\n", *nbr);
		parse_nbr(r, *nbr++, 0);
		++r->size;
		r->bd & STRING && *nbr ? r->bd |= ERR : 0;
	}
	return (r->bd & ERR ? 0 : 1);
}
