#include "push_swap.h"

static	void	init_best(t_roll *r, int *best, int i)
{
//	display_piles(r, &r->a, &r->b);/////////////////////////////////////////////////
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
//	ft_printf("{blue}{bold}{underline}IN\tFIND BEST SORT{eoc}\n");///////////////
	int		best[size];

	init_best(r, best, -1);
	for (int test = 0; test < size; test++)
		ft_printf("[{green}%4+d{eoc}] ", t[test]);
	ft_printf("\n");
	while (++i < (int)r->nb_a)
	{
//		display_pile(r, &r->a, 'A');/////////////////////////////////////////////
//		ft_printf("-> i = %d\t", i);/////////////////////////////////////////////
//		ft_printf("best[%d] = %d\t", i, best[i]);////////////////////////////////
//		ft_printf("t[%d] = %d\t", i, t[i]);//////////////////////////////////////
		if (best[i] != t[i])
		{
//			ft_printf("{red}{underline}best[%d] != t[%d]){eoc}\t", i, i);/////
			if (i + 1 <= (int)r->nb_a)
			{
//				ft_printf("{green}{underline}i + 1 <= r->size{eoc}\t");//////
				if (best[i] == t[i + 1] && best[i + 1] == t[i])
				{
//					ft_printf("{green}SWAP : best[i + j] == t[i + j + 1] && best[i + j + 1] == t[i + j]{eoc}");//
					r->a.low->bd |= SWAP;
					rotate(NULL, &r->a, 0);
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
//				ft_printf("{red}{underline}i + j > r->size -> pushb{eoc}\n");//
				r->a.low->bd |= PUSH;
			}
		}
		else
		{
//			ft_printf("{green}best[%d] == t[%d]\t{eoc}", i, i);//////////////////////
			r->a.low->bd |= GOOD;
		}
		rotate(NULL, &r->a, 0);
//		ft_printf("\n\n");/////////////////////////////////////////////////////////
	}
//	ft_printf("\n");/////////////////////////////////////////////////////////////
//	display_piles(r, &r->a, &r->b);/////////////////////////////////////////////////
	find_best_rotation(r, r->b_rot, 0);//////////////////////////////////////////
//	ft_printf("{blue}{bold}{underline}END\tFIND BEST SORT{eoc}\n\n");////////////
}

void		find_best_rotation(t_roll *r, int rot, int state)
{
//	ft_printf("{blue}{bold}{underline}IN\tFIND BEST ROTATION{eoc} rot = %d\n", rot);//
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
//	ft_printf("{blue}{bold}{underline}END\tFIND BEST ROTATION{eoc}\n\n");////////
}

void			find_best_combinaison(int *t, t_roll *r, int i)
{
//	ft_printf("{blue}{bold}{underline}\nIN\tFIND BEST COMBINAISON{eoc}\n");//////
	int			j;
	int			cor;
	t_pile		*tmp;

	r->b_rot = 0;
	r->cor = 0;
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
//	ft_printf("{blue}{bold}{underline}END\tFIND BEST COMBINAISON{eoc}\n\n");/////
}
