#include "push_swap.h"

static	void	init_best(t_roll *r, int *best, int i)
{
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	find_best_rotation(r, r->b_rot, ROT | R_ROT);
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	while (++i < (int)r->nb_a)
	{
		best[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
}

void		find_best_sort(int *t, t_roll *r, int size, int i)
{
	int		best[size];

	init_best(r, best, -1);
	while (++i < (int)r->nb_a)
	{
//		display_pile(r, &r->a, 'A');/////////////////////////////////////////////
//		ft_printf("-> i = %d\t", i);/////////////////////////////////////////////
//		ft_printf("*best = %d\t", best[i]);//////////////////////////////////////
//		ft_printf("(*t).n = %d\t", t[i].n);//////////////////////////////////////
		if (r->a.low->bd & (ROT | R_ROT))
		{
			if (best[i] != t[i])
			{
//				ft_printf("{red}{underline}*best != (*t).n){eoc}\t");////////////////
				if (i + 1 <= (int)r->nb_a)
				{
//					ft_printf("{green}{underline}i + 1 <= r->size{eoc}\t");//////////
					if (best[i] == t[i + 1] && best[i + 1] == t[i])
					{
//						ft_printf("{green}SWAP : best[i + j] == t[i + j + 1] && best[i + j + 1] == t[i + j]{eoc}");//
						r->a.low->bd |= SWAP;
						r->a.low->bd |= GOOD;
						rotate(NULL, &r->a, 0);
						r->a.low->low->bd |= GOOD;
						++i;
					}
					else
					{
//						ft_printf("{red}PUSH : best[i] != t[i + 1] || best[i + 1] != t[i]{eoc}");//
						r->a.low->bd |= PUSH;
					}
				}
				else
				{
//					ft_printf("{red}{underline}i + j > r->size -> pushb{eoc}\n");////
					r->a.low->bd |= PUSH;
				}
			}
			else
			{
//				ft_printf("{green}*best == (*t).n\t{eoc}");//////////////////////////
				r->a.low->bd |= GOOD;
			}
		}
		rotate(NULL, &r->a, 0);
//		ft_printf("\n");/////////////////////////////////////////////////////////
	}
//	ft_printf("\n");/////////////////////////////////////////////////////////////
//	display_pile(r, &r->a, 'A');/////////////////////////////////////////////////
	find_best_rotation(r, r->b_rot, 0);//////////////////////////////////////////
//	ft_printf("{blue}{bold}{underline}\nEND\tFIND BEST SORT{eoc}\n");////////////
}

void		find_best_rotation(t_roll *r, int rot, int state)
{
	if (rot > (int)r->nb_a / 2)
	{
		while (rot++ < (int)r->nb_a)
		{
			rotate(NULL, &r->a, 0);
			state & R_ROT ? r->a.low->bd |= R_ROT : 0;
		}
	}
	else
	{
		while (rot-- > 0)
		{
			r_rotate(NULL, &r->a, 0);
			state & ROT ? r->a.low->bd |= ROT : 0;
		}
	}
}

void			find_best_combinaison(int *t, t_roll *r, int i)
{
	int			j;
	int			cor;
	t_pile		*tmp;

	while (++i < (int)r->nb_a)
	{
		tmp = &r->a;
		j = -1;
		cor = 0;
		while (++j < (int)r->nb_a)
		{
			tmp->LNBR == t[j] ? ++cor : 0;
			rotate(NULL, tmp, 0);
		}
		cor > r->cor ? r->b_rot = i : 0;
		cor > r->cor ? r->cor = cor : 0;
		rotate(NULL, &r->a, 0);
	}
}
