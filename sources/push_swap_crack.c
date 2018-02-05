#include "push_swap.h"

static	void	init_best(t_roll *r, t_tab *t, int *best, int i)
{
//	ft_printf("{yellow}{bold}{underline}\nIN\tINIT BEST{eoc}\n");////////////////
	find_best_rotation(r, r->size - r->b_rot, 0);
	find_best_rotation(r, r->b_rot, ROT | R_ROT);
	find_best_rotation(r, r->size - r->b_rot, 0);
//	ft_printf("\n");/////////////////////////////////////////////////////////////
	while (++i < r->size)
	{
		best[i] = r->a.low->nbr;
//		ft_printf("best[%6d] = %d\tt[%6d].n = %d\n", i, best[i], i, t[i].n);/////
		rotate(NULL, &r->a, 0);
	}
	(void)t;//le pointeur t est inutil appart pour le debug//////////////////////
//	display_pile(r, &r->a, 'A');/////////////////////////////////////////////////
//	ft_printf("{yellow}{bold}{underline}END\tINIT BEST{eoc}\n\n");///////////////
}

void		find_best_sort(t_tab *t, t_roll *r, int size, int i)
{
//	ft_printf("{blue}{bold}{underline}IN\tFIND BEST SORT{eoc}\n");///////////////
	int		best[size];

//	display_pile(r, &r->a, 'A');/////////////////////////////////////////////////
	init_best(r, t, best, -1);
	while (++i < (int)r->nb_a)
	{
//		display_pile(r, &r->a, 'A');/////////////////////////////////////////////
//		ft_printf("-> i = %d\t", i);/////////////////////////////////////////////
//		ft_printf("*best = %d\t", best[i]);//////////////////////////////////////
//		ft_printf("(*t).n = %d\t", t[i].n);//////////////////////////////////////
		if (best[i] != t[i].n)
		{
//			ft_printf("{red}{underline}*best != (*t).n){eoc}\t");////////////////
			if (i + 1 <= (int)r->nb_a)
			{
//				ft_printf("{green}{underline}i + 1 <= r->size{eoc}\t");//////////
				if (best[i] == t[i + 1].n && best[i + 1] == t[i].n)
				{
//					ft_printf("{green}SWAP : best[i + j] == t[i + j + 1] && best[i + j + 1] == t[i + j]{eoc}");//
					r->a.low->bd |= SWAP;
					r->a.low->bd |= GOOD;
					rotate(NULL, &r->a, 0);
					r->a.low->low->bd |= GOOD;
					++i;
				}
				else
				{
//					ft_printf("{red}PUSH : best[i] != t[i + 1] || best[i + 1] != t[i]{eoc}");//
					r->a.low->bd |= PUSH;
				}
			}
			else
			{
//				ft_printf("{red}{underline}i + j > r->size -> pushb{eoc}\n");////
				r->a.low->bd |= PUSH;
			}
		}
		else
		{
//			ft_printf("{green}*best == (*t).n\t{eoc}");//////////////////////////
			r->a.low->bd |= GOOD;
		}
		rotate(NULL, &r->a, 0);
//		ft_printf("\n");/////////////////////////////////////////////////////////
	}
//	ft_printf("\n");/////////////////////////////////////////////////////////////
//	display_pile(r, &r->a, 'A');/////////////////////////////////////////////////
	find_best_rotation(r, r->b_rot, 0);//////////////////////////////////////////
//	display_pile(r, &r->a, 'A');/////////////////////////////////////////////////
//	ft_printf("{blue}{bold}{underline}\nEND\tFIND BEST SORT{eoc}\n");////////////
}

void		find_best_rotation(t_roll *r, int rot, int state)
{
//	ft_printf("{red}{bold}{underline}IN\tFIND BEST ROTATION{eoc}\n");////////////

	if (rot > (int)r->nb_a / 2)
	{
//		ft_printf ("best rot > size / 2 (rotate)\n");////////////////////////////
		while (rot++ < (int)r->nb_a)
		{
			rotate(NULL, &r->a, 0);
//			display_pile(r, &r->a, 'T');/////////////////////////////////////////
			state & R_ROT ? r->a.low->bd |= R_ROT : 0;
		}
	}
	else
	{
//		ft_printf ("best rot <= size / 2 (r_rotate)\n");/////////////////////////
		while (rot-- > 0)
		{
			r_rotate(NULL, &r->a, 0);
//			display_pile(r, &r->a, 'T');/////////////////////////////////////////
			state & ROT ? r->a.low->bd |= ROT : 0;
		}
	}
//	display_pile(r, &r->a, 'A');/////////////////////////////////////////////////
//	ft_printf("{red}{bold}{underline}END\tFIND BEST ROTATION{eoc}\n");///////////
}

void			find_best_combinaison(t_tab *t, t_roll *r, int i)
{
//	ft_printf("{green}{bold}{underline}IN\tFIND BEST COMBINAISONON{eoc}\n");////
	int			j;
	int			cor;
	t_pile		*tmp;

	while (++i < (int)r->nb_a)
	{
		tmp = &r->a;
//		display_pile(r, tmp, 'T');//////////////////////////////////////////////
		j = -1;
		cor = 0;
		while (++j < (int)r->nb_a)
		{
			tmp->low->nbr == (int)t[j].n ? ++cor : 0;
			rotate(NULL, tmp, 0);
		}
//		ft_printf("correspondance = %d\n\n", cor);///////////////////////////////
		cor > r->cor ? r->b_rot = i : 0;
		cor > r->cor ? r->cor = cor : 0;
		rotate(NULL, &r->a, 0);
	}
//	r->cor == r->size ? ft_printf("{green}tri relatif!!!{eoc}\n") : 0;///////////
//	ft_printf("r->cor = %d\tr->b_rot = %d\n", r->cor, r->b_rot);/////////////////
//	ft_printf("{green}{bold}{underline}END\tFIND BEST COMBINAISON{eoc}\n\n");////
}
